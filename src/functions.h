#ifndef __FUNCTINS_INCLUDE__
#define __FUNCTINS_INCLUDE__

#include "globals.h"
void output(int level, const char* fmt, ...);

#ifdef _WIN32
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

void clear_temp();
void die(const char* error, ...);

#endif // #ifndef __FUNCTINS_INCLUDE__
