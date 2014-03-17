#ifndef __GEOTIFF_INCLUDE__
#define __GEOTIFF_INCLUDE__

// some defintions for geotiff

#define TIFFTAG_GEOPIXELSCALE   33550
#define TIFFTAG_GEOTIEPOINTS    33922
#define TIFFTAG_GEOTRANSMATRIX  34264  
#define TIFFTAG_GEOKEYDIRECTORY 34735
#define TIFFTAG_GEODOUBLEPARAMS 34736
#define TIFFTAG_GEOASCIIPARAMS  34736

#define TIFFTAG_GDAL_NODATA     42113


static const TIFFFieldInfo xtiffFieldInfo[] = {
  /* XXX Insert Your tags here */
  { TIFFTAG_GEOPIXELSCALE, -1,-1, TIFF_DOUBLE,FIELD_CUSTOM,
    TRUE,TRUE,(char*)"GeoPixelScale" },
  { TIFFTAG_GEOTRANSMATRIX, -1,-1, TIFF_DOUBLE,FIELD_CUSTOM,
    TRUE,TRUE,(char*)"GeoTransformationMatrix" },
  { TIFFTAG_GEOTIEPOINTS, -1,-1, TIFF_DOUBLE,FIELD_CUSTOM,
    TRUE,TRUE,(char*)"GeoTiePoints" },
  { TIFFTAG_GEOKEYDIRECTORY, -1,-1, TIFF_SHORT,FIELD_CUSTOM,
    TRUE,TRUE,(char*)"GeoKeyDirectory" },
  { TIFFTAG_GEODOUBLEPARAMS, -1,-1, TIFF_DOUBLE,FIELD_CUSTOM,
    TRUE,TRUE,(char*)"GeoDoubleParams" },
  { TIFFTAG_GEOASCIIPARAMS, -1,-1, TIFF_ASCII,FIELD_CUSTOM,
    TRUE,FALSE,(char*)"GeoASCIIParams" },
  { TIFFTAG_GDAL_NODATA, -1,-1, TIFF_ASCII,FIELD_CUSTOM,
    TRUE,FALSE,(char*)"GDALNoDataValue" }
};

void geotiff_register(TIFF* tif);
int geotiff_read(TIFF* tiff, GeoTIFFInfo* info);
int geotiff_write(TIFF * tiff, GeoTIFFInfo * info);

#endif // #ifndef __GEOTIFF_INCLUDE__
