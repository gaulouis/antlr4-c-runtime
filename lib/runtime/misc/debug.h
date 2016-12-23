#ifndef __ANTLR_DEBUG_H__
#define __ANTLR_DEBUG_H__

ANTLR_BEGIN_DECLS

typedef enum _AntlrDebugFlag AntlrDebugFlag;

enum _AntlrDebugFlag {
    ANTLR_DEBUG_FLAG_NONE = 0,
    ANTLR_DEBUG_FLAG_DFA  = 1<<0,
    ANTLR_DEBUG_FLAG_TRY  = 1<<1,
    ANTLR_DEBUG_FLAG_ALL  = ANTLR_DEBUG_FLAG_DFA|ANTLR_DEBUG_FLAG_TRY,
    ANTLR_DEBUG_FLAGS
};

static int antlr_debug_initialized = 0;

int antlr_debug_get_flags(void);

ANTLR_END_DECLS

#endif // __ANTLR_DEBUG_H__
