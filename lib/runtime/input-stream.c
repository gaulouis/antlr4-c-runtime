/*
 * [The "BSD 3-clause license"]
 * Copyright (c) 2012-2016 The ANTLR Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "types.h"

#include "misc/macro.h"
#include "misc/type.h"
#include "misc/object.h"

#include "int-stream-interface.h"
#include "char-stream-interface.h"

#include "input-stream.h"



static void antlr_input_stream_interface_int_stream_init(AntlrIntStreamInterface *iface);
static void antlr_input_stream_interface_char_stream_init(AntlrCharStreamInterface *iface);

//ANTLR_DEFINE_TYPE(AntlrInputStream, antlr_input_stream, ANTLR_TYPE_OBJECT)
ANTLR_DEFINE_TYPE_WITH_CODE (AntlrInputStream, antlr_input_stream, ANTLR_TYPE_OBJECT,
                         ANTLR_IMPLEMENT_INTERFACE(ANTLR_TYPE_INT_STREAM, antlr_input_stream_interface_int_stream_init)
                         ANTLR_IMPLEMENT_INTERFACE(ANTLR_TYPE_CHAR_STREAM, antlr_input_stream_interface_char_stream_init)
                         )

#define parent_class antlr_input_stream_parent_class
static void
antlr_input_stream_class_object_destroy(AntlrObject *object)
{
    ANTLR_OBJECT_CLASS(parent_class)->destroy(object);
}

static void
antlr_input_stream_class_init(AntlrInputStreamClass *klass)
{
    ANTLR_OBJECT_CLASS(klass)->destroy = antlr_input_stream_class_object_destroy;
}



#include <stdio.h>
#include "misc/debug.h"
static int antlr_input_stream_debug = -1;

static void
antlr_input_stream_interface_int_stream_consume(AntlrIntStreamI *stream)
{
    AntlrInputStream *self = ANTLR_INPUT_STREAM(stream);
    if (-1==antlr_input_stream_debug) {
        antlr_input_stream_debug = antlr_debug_get_flag(ANTLR_DEBUG_FLAG_ALL);
    }

    if (antlr_input_stream_debug) {
        printf("consume\n");
    }
}

static void
antlr_input_stream_interface_int_stream_init(AntlrIntStreamInterface *iface)
{
    iface->consume = antlr_input_stream_interface_int_stream_consume;
}

static void
antlr_input_stream_interface_char_stream_init(AntlrCharStreamInterface *iface)
{
    iface->get_text = 0;
}

void
antlr_input_stream_init(AntlrInputStream *self)
{
}

AntlrInputStream*
antlr_input_stream_new(void)
{
    AntlrInputStream *stream = antlr_object_new(antlr_input_stream_get_type());
    return stream;
}
