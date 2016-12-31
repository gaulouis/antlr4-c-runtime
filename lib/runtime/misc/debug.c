#include "macro.h"

#include "debug.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static unsigned int antlr_debug_flags = 0x00;
static int antlr_debug_flags_initialized = 0;

/*
 * Usage:
 *
 * static int antlr_atn_simulator_debug_dfa = FALSE;
 *
 * ...
 *
 * if(! antlr_debug_initialized ) {
 *     //antlr_debug_init();
 *     antlr_debug_initialized = 1;
 *     antlr_debug_flags = antlr_debug_get_flags();
 *
 *
 *     antlr_atn_simulator_debug_dfa = (antlr_debug_flags & ~ANTLR_DEBUG_FLAG_DFA) ? 1 : 0;
 * }
 * if (antlr_atn_simulator_debug_dfa | ...) {
 *   print...
 * }
 *
 */

static unsigned int
antlr_debug_get_flags(void)
{
    unsigned int debug_flags = 0x00;
    const char *delimiter = " ,";
    char *debug_env = getenv("ANTLR_DEBUG");
    if (debug_env) {
        char *pch;
        for (pch = strtok (debug_env, delimiter); pch; pch = strtok (NULL, delimiter)) {
            if (strcmp(pch, "all")==0) {
                debug_flags |= ANTLR_DEBUG_FLAG_ALL;
            } else if (strcmp(pch, "dfa")==0) {
                debug_flags |= ANTLR_DEBUG_FLAG_DFA;
            } else if (strcmp(pch, "try")==0) {
                debug_flags |= ANTLR_DEBUG_FLAG_TRY;
            } else {
                printf ("Notice: \"%s\" is not a valid ANTLR_DEBUG flag\n",pch);
            }
        }
    }

    return debug_flags;
}

int
antlr_debug_get_flag(unsigned int flag)
{
    if (! antlr_debug_flags_initialized) {
        antlr_debug_flags = antlr_debug_get_flags();
        antlr_debug_flags_initialized = 1;
    }

    return (antlr_debug_flags & flag)==flag ? 1 : 0;
}

