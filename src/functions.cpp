#include "functions.h"

void output(int level, const char* fmt, ...) {
    va_list args;

    if (level<=g_verbosity) {
        va_start(args,fmt);
        vprintf(fmt,args);
        va_end(args);
    }
}

void report_time(const char* name, double time) {
    if (g_timing) output(0,"%s: %.3fs\n",name,time);
}

void clear_temp() {
    int i,c;

    for (i=0; i<g_numimages; i++) {
        for (c=0; c<g_numchannels; c++) {
            if (g_images[i].channels[c].f) {
                fclose(g_images[i].channels[c].f);
#ifdef _WIN32
                DeleteFile((LPCTSTR)g_images[i].channels[c].filename);
#endif
            }
        }
    }
}

void die(const char* error, ...) {
    va_list args;

    va_start(args,error);
    vprintf(error,args);
    va_end(args);
    printf("\n");

    clear_temp();

    if (g_debug) {
        printf("\nPress Enter to end\n");
        getchar();
    }
    exit(1);
}
