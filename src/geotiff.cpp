#include "globals.h"
#include "geotiff.h"
#include "functions.h"

void geotiff_register(TIFF* tif) {
  TIFFMergeFieldInfo(tif, xtiffFieldInfo, sizeof(xtiffFieldInfo)/sizeof(xtiffFieldInfo[0]));
}

/** Read geotiff tags from an image. Only accept images with correct geocoding.

    Returns  1 if reading was successfull, 0 if it failed.
*/
int geotiff_read(TIFF* tiff, GeoTIFFInfo* info) {
  unsigned short nCount=0;
  double* geo_scale;
  // clear geotiff info
//  memset(info,0,sizeof(GeoTIFFInfo));
  geotiff_register(tiff);

  if (!TIFFGetField(tiff, TIFFTAG_GEOPIXELSCALE, &nCount, &geo_scale) || nCount<2) return false;

	info->XCellRes = geo_scale[0];
  info->YCellRes = geo_scale[1];
  double* tiepoints;

	if (!TIFFGetField(tiff, TIFFTAG_GEOTIEPOINTS, &nCount, &tiepoints) || nCount<6) return false;
  info->XGeoRef = tiepoints[3] - tiepoints[0]*(geo_scale[0]);
  info->YGeoRef = tiepoints[4] - tiepoints[1]*(geo_scale[1]);
  // TODO: check if tiepoints refer to center of upper left pixel or upper left edge of upper left pixel
  char* nodata;

	if (TIFFGetField(tiff, TIFFTAG_GDAL_NODATA, &nCount, &nodata)) info->nodata = atoi(nodata);

	// TODO: read coordinate system definitions...
	info->set=true;
  return true;
}

/** Write geotiff tags to an image */
int geotiff_write(TIFF * tiff, GeoTIFFInfo * info) {
  geotiff_register(tiff);
  double scale[3];
  scale[0]=info->XCellRes;
  scale[1]=info->YCellRes;
  scale[2]=0.0;
  TIFFSetField(tiff, TIFFTAG_GEOPIXELSCALE, 3, scale);
  double tiepoint[6];
  tiepoint[0] = tiepoint[1] = tiepoint[2] = tiepoint[5] = 0;
  tiepoint[3] = info->XGeoRef;
  tiepoint[4] = info->YGeoRef;
  TIFFSetField(tiff, TIFFTAG_GEOTIEPOINTS, 6, tiepoint);
  char nodata[50];
  SNPRINTF(nodata,50,"%d",info->nodata);
  TIFFSetField(tiff, TIFFTAG_GDAL_NODATA, nodata);
  return 1;
}
