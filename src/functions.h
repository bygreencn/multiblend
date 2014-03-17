#ifndef __FUNCTINS_INCLUDE__
#define __FUNCTINS_INCLUDE__

#include "globals.h"
void output(int level, const char* fmt, ...);

#ifdef WIN32
class my_timer {
public:
	void set() {
		QueryPerformanceCounter(&t1);
	}

	double read() {
		QueryPerformanceCounter(&t2);
		return (double)(t2.QuadPart-t1.QuadPart)/frequency.QuadPart;
	}

	my_timer() {
		QueryPerformanceFrequency(&frequency);
	}

	void report(const char* name) {
		if (g_timing) output(0,"%s: %.3fs\n",name,this->read());
	}
private:
	LARGE_INTEGER t1;
	LARGE_INTEGER t2;
	LARGE_INTEGER frequency;
};
#else
class my_timer {
public:
	void set() { }
	double read() { return 0; }
  void report(const char* name) { if (g_timing) printf("Timing not available\n"); }
};
#endif

void report_time(const char* name, double time);

#ifndef WIN32
#define SNPRINTF snprintf
int _stricmp(const char* a, const char* b) { return strcasecmp(a,b); }
void* _aligned_malloc(size_t size, int boundary) { return memalign(boundary,size); }
void _aligned_free(void* a) { free(a); }
void fopen_s(FILE** f,const char* filename, const char* mode) { *f=fopen(filename,mode); }
#else
#define SNPRINTF _snprintf_s
#endif

void clear_temp();
void die(const char* error, ...);

#endif // #ifndef __FUNCTINS_INCLUDE__
