// debug.h

#ifndef DEBUG_H
#define DEBUG_H

// Funktio jolla asetetaan debug
void set_debug_level(int debug_level);

// Debug tulostusfunktio jossa on oma debug 
int dprintf(int debug_level, const char *fmt, ...);

#endif // DEBUG_H
