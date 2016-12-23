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

#ifndef __ANTLR_OBJECT_H__
#define __ANTLR_OBJECT_H__


#define ANTLR_OBJECT(obj)           ((AntlrObject*)obj)
#define ANTLR_TYPE_OBJECT           (antlr_object_get_type())
#define ANTLR_OBJECT_CLASS(klass)   ((AntlrObjectClass*)klass)
#define ANTLR_OBJECT_GET_CLASS(obj) ((AntlrObjectClass*)(antlr_type_get_class()[ANTLR_TYPE_OBJECT]))

typedef struct _AntlrRef         AntlrRef;
typedef struct _AntlrObject      AntlrObject;
typedef struct _AntlrObjectClass AntlrObjectClass;

struct _AntlrRef {
    int count;
};
struct _AntlrObject {
    /*< private >*/
    AntlrRef ref;
    AntlrType type;
};

struct _AntlrObjectClass {
    /*< private >*/
    AntlrType parent_type;

    /*< public >*/
    AntlrPtr     (*construct) (void);
    void         (*init)      (AntlrObject* self);
    void         (*destroy)   (AntlrObject* self);

#if defined(ENABLE_DEBUG) && ENABLE_DEBUG
    char *name;
#endif
};

AntlrType antlr_object_get_type(void);
AntlrPtr  antlr_object_new(AntlrType type);
void      antlr_object_destroy(AntlrObject *object);
void      antlr_object_ref(AntlrObject *object);
void      antlr_object_unref(AntlrObject *object);
//AntlrInputStream *stream = antlr_object_new(antlr_input_stream_get_type());
char*     antlr_object_get_name(AntlrObject *object);



#endif // __ANTLR_OBJECT_H__
