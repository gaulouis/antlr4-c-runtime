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

#ifndef __ANTLR_INPUT_STREAM_H__
#define __ANTLR_INPUT_STREAM_H__


ANTLR_BEGIN_DECLS


#define ANTLR_TYPE_INPUT_STREAM           (antlr_input_stream_get_type())
#define ANTLR_INPUT_STREAM(obj)           ((AntlrInputStream*)obj)
#define ANTLR_INPUT_STREAM_CLASS(klass)   ((AntlrInputStreamClass*)klass)
#define ANTLR_INPUT_STREAM_GET_CLASS(obj) ((AntlrInputStreamClass*)(antlr_type_get_class()[ANTLR_TYPE_INPUT_STREAM]))


//#define ANTLR_INPUT_STREAM_GET_TYPE(obj)  ANTLR_OBJECT(obj)->type
//#define ANTLR_INPUT_STREAM_GET_CLASS(obj)
// ((AntlrInputStreamClass*)antlr_class[ANTLR_OBJECT(obj)->type])

typedef struct _AntlrInputStream      AntlrInputStream;
typedef struct _AntlrInputStreamClass AntlrInputStreamClass;

struct _AntlrInputStream
{
    /*< private >*/
    AntlrObject parent_instance;

    /*< public >*/
    char *name;
    char* data;
    int n;
    int p;
};

struct _AntlrInputStreamClass
{
    /*< private >*/
    AntlrObjectClass parent_class;
    AntlrIntStreamInterface AntlrIntStreamMember;
    AntlrCharStreamInterface AntlrCharStreamMember;

    /*< public >*/
    // public virtual methods
};

AntlrType         antlr_input_stream_get_type(void);
AntlrInputStream *antlr_input_stream_new(void);

ANTLR_END_DECLS

#endif // __ANTLR_INPUT_STREAM_H__
