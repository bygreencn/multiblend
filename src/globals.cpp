#include "globals.h"

#ifndef _WIN32
#include <stdlib.h>
#include <malloc.h>
#endif

void* g_line0;
void* g_line1;
void* g_line2;
void* g_linet;

void* g_temp;
int* g_dither;

int g_numthreads;

int g_numimages=0;
int g_workwidth=0;
int g_workheight=0;
int g_workbpp=0;
int g_workbpp_cmd=0;
int g_min_top=0;
int g_min_left=0;
double g_xres=-1;
double g_yres=-1;
int  g_levels;
int  g_max_levels=1000000;
int  g_sub_levels=0;
int  g_verbosity=1;
bool g_wideblend=false;
bool g_seamwarning=false;
bool g_reverse=false;
bool g_pseudowrap=false;
bool g_swap=false;
bool g_save_out_pyramids=false;
bool g_dewhorl=false;
char* g_output_filename;
char* g_seamload_filename;
png_color* g_palette;
char*   g_seamsave_filename;
char*   g_xor_filename;
int    g_numchannels=3;
void** g_out_channels;
TIFF*  g_tiff;
FILE*  g_jpeg;
uint16    g_compression = 1; // ¸³Öµ¸ø(uint)tif_dir.td_compressionÊ±»á²úÉú65535£¬ËùÒÔ¸Ä±äÀàÐÍ¡£
int    g_jpegquality=-1;
uint32* g_seams;
bool g_timing=true;
bool g_savemasks=false;
bool g_nooutput=false;
bool g_caching=false;

size_t g_cache_bytes=0;

struct_level* g_output_pyramid;

bool g_crop=true;
bool g_debug=true;
bool g_nomask=false;
bool g_bigtiff=false;
bool g_bgr=false;

uint32* g_edt;

struct_image* g_images;


#ifndef _WIN32
int _stricmp(const char* a, const char* b) { return strcasecmp(a,b); }
void* _aligned_malloc(size_t size, int boundary) { return memalign(boundary,size); }
void _aligned_free(void* a) { free(a); }
void fopen_s(FILE** f,const char* filename, const char* mode) { *f=fopen(filename,mode); }
#endif
