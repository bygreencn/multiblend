#ifndef __LOADIMGES_CPP__
#define __LOADIMGES_CPP__

#include "globals.h"
#include "functions.h"

#define I g_images[i]

void extract(struct_image* image, void* bitmap);
void extract16(struct_image* image, void* bitmap);
void extract8(struct_image* image, void* bitmap);
void inpaint(struct_image* image, uint32* edt);
void inpaint16(struct_image* image, uint32* edt);
void inpaint8(struct_image* image, uint32* edt);
void load_images(char** argv, int argc);
void tighten();
void trim(void* bitmap, int w, int h, int bpp, int* top, int* left, int* bottom, int* right);
void trim16(void* bitmap, uint32 w, uint32 h, int bpp, int* top, int* left, int* bottom, int* right);
void trim8(void* bitmap, uint32 w, uint32 h, int bpp, int* top, int* left, int* bottom, int* right);

#endif // #ifndef __LOADIMGES_CPP__
