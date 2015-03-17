#ifndef __GLOBALS_INCLUDE__
#define __GLOBALS_INCLUDE__

#include "tiffio.h"
#include "tiff.h"
#include "png.h"
#include "jpeglib.h"
#include "turbojpeg.h"


#ifndef _WIN32
#include "malloc.h"
#endif

#ifdef _WIN32
#include "BaseTsd.h"
#include <Windows.h>
#include <Winnt.h>
#define SNPRINTF _snprintf_s
#else
#include <stdio.h>
#include "malloc.h"
#include "stdlib.h"
#define SNPRINTF snprintf
void fopen_s(FILE** f,const char* filename, const char* mode);
int _stricmp(const char* a, const char* b);
void* _aligned_malloc(size_t size, int boundary);
void _aligned_free(void* a);
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#endif

void die(const char* error, ...);
void output(int level, const char* fmt, ...);

extern void* g_line0;
extern void* g_line1;
extern void* g_line2;
extern void* g_linet;

extern void* g_temp;

extern int* g_dither;

struct struct_indexed {
    //  int size;
    //  uint32 p;
    uint32* pointer;
    uint32* data;
    uint32* rows;
    //  uint32* w;
    //  uint32* h;
};

struct struct_level {
    void*  data;
    size_t offset;
    int    x0,y0; // inclusive minimum coordinates within this extended level
    int    x1,y1; // inclusive maximum coordinates within this extended level
    int    w,h;
    int    pitch;
};

struct GeoTIFFInfo {
    double XGeoRef, YGeoRef;
    double XCellRes, YCellRes;
    double projection[16];
    int    nodata;
    bool   set;
};

struct struct_channel {
    void* data;
    char* filename;
    FILE* f;
};

struct struct_image {
    char filename[256];
    uint16 bpp;
    int width,height;
    int xpos,ypos;
    int top,left;
    struct_channel* channels;
    struct_indexed binary_mask;
    struct_level* pyramid;
    float** masks;
    bool seampresent;
    GeoTIFFInfo geotiff;
    TIFF* tiff;
    int tiff_width;
    int tiff_height;
    int tiff_u_height;
    int first_strip;
    int last_strip;
};

extern int g_numthreads;

extern int g_numimages;
extern int g_workwidth;
extern int g_workheight;
extern int g_workbpp;
extern int g_workbpp_cmd;
extern int g_min_top;
extern int g_min_left;
extern double g_xres;
extern double g_yres;
extern int  g_levels;
extern int  g_max_levels;
extern int  g_sub_levels;
extern int  g_verbosity;
extern bool g_wideblend;
extern bool g_seamwarning;
extern bool g_reverse;
extern bool g_pseudowrap;
extern bool g_swap;
extern bool g_save_out_pyramids;
extern bool g_dewhorl;
extern char* g_output_filename;
extern char* g_seamload_filename;
extern png_color* g_palette;
extern char*   g_seamsave_filename;
extern char*   g_xor_filename;
extern int    g_numchannels;
extern void** g_out_channels;
extern TIFF*  g_tiff;
extern FILE*  g_jpeg;
extern uint16    g_compression; // 赋值给(uint)tif_dir.td_compression时会产生65535，所以改变类型。
extern int    g_jpegquality;
extern uint32* g_seams;
extern bool g_timing;
extern bool g_savemasks;
extern bool g_nooutput;
extern bool g_caching;
extern size_t g_cache_bytes;

extern struct_level* g_output_pyramid;

extern bool g_crop;
extern bool g_debug;
extern bool g_nomask;
extern bool g_bigtiff;
extern bool g_bgr;

extern uint32* g_edt;

#define PY(i,l) g_images[i].pyramid[l]

extern struct_image* g_images;

#endif // #ifndef __GLOBALS_INCLUDE__
