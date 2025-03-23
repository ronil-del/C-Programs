// debug.c

#include "debug.h"
#include <stdio.h>
#include <stdarg.h>

// Staattinen muuttuja joka pitää sisällään debug 
static int debug_level = 0;

// Funktio jolla asetetaan debug
void set_debug_level(int level) {
    // Varmistetaan, että debug on välillä 0-4
    if (level >= 0 && level <= 4) {
        debug_level = level;
    }
}

// Funktio joka tulostaa viestejä riippuen debug 
int dprintf(int level, const char *fmt, ...) {
    if (level <= debug_level) {
        // Tulostetaan debug viesti tietyllä debug
        va_list args;
        va_start(args, fmt);
        fprintf(stderr, "[DBG%d] ", level);  // Lisätään viestin alkuun debug
        vfprintf(stderr, fmt, args);          // Tulostetaan itse viesti
        va_end(args);
        return 1;
    }
    return 0;  // Ei tehdä mitään jos debug on korkeampi kuin asetettu 
}
