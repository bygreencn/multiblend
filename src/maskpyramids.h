#ifndef __MASKPYRAMIDS_INCLUDE__
#define __MASKPYRAMIDS_INCLUDE__

#include "globals.h"

union intfloat {
	float f;
	int i;
};

void extract_top_masks();
void mask_pyramids();
void png_mask(int i);
void shrink_mask(float* input, float **output_pointer, int inwidth, int inheight, int outwidth, int outheight);
void shrink_masks();
int squash_lines(float* a, float* b, float* c, float* o, int width);
int squish_line(float* input, float *output, int inwidth, int outwidth);

#endif // #ifndef __MASKPYRAMIDS_INCLUDE__
