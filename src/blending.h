#ifndef __BLENDING_H__
#define __BLENDING_H__

#include "globals.h"

#define ACCURACY 5 // don't change this

#define NEXT_MASK { \
	pixel.f=*mask++; \
 	if (pixel.i<0) { \
  	count=-pixel.i; \
  	pixel.f=*mask++; \
	} else count=1; \
}

void blend();
void collapse(struct_level* lower, struct_level* upper);
void copy_channel(int i, int c);
void dither(struct_level* top, void* channel);
void hps(struct_level* upper, struct_level *lower);
void hshrink(struct_level* upper, struct_level* lower);
__inline void inflate_line_int(int *input, int *output, int w);
__inline void inflate_line_short(short *input, short *output, int w);
void mask_into_output(struct_level* input, float* mask, struct_level* output, bool first);
void save_out_pyramid(int c, bool collapsed);
void shrink_hps(struct_level* upper, struct_level* lower);
void vshrink(struct_level* upper, struct_level* lower);


#endif // #ifndef __BLENDING_H__
