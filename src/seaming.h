#ifndef __SEAMING_INCLUDE__
#define __SEAMING_INCLUDE__

#define NEXTiMASK(i) { temp=*g_images[i].binary_mask.pointer++; maskcount[i]=temp&0x7fffffff; mask[i]=~temp&0x80000000; }
#define PREViMASK(i) { temp=*--g_images[i].binary_mask.pointer; maskcount[i]=temp&0x7fffffff; mask[i]=~temp&0x80000000; }

#define MASKON 0

#define MASKOFF 0x80000000
void leftupxy();
void load_seams();
void make_seams();
void rightdownxy();
void seam();
void seam_png(int mode, const char* filename);

#endif // #ifndef __SEAMING_INCLUDE__
