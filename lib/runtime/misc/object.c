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


#include "../types.h"

#include "macro.h"
#include "type.h"

#include "object.h"


ANTLR_DEFINE_TYPE(AntlrObject, antlr_object, ANTLR_TYPE_NONE)


//static AntlrPtr
//antlr_object_class_object_construct(void)
//{
//    // This is an abstract class ?
//    return 0;
//}

static void
antlr_object_class_object_init(AntlrObject *object)
{
    object->ref.count = 1;
}

static void
antlr_object_class_object_destroy(AntlrObject *object)
{
    free(object);
}

static void
antlr_object_class_init(AntlrObjectClass *klass)
{
//    klass->construct = antlr_object_class_object_construct; set by macro
    klass->init      = antlr_object_class_object_init;
    klass->destroy   = antlr_object_class_object_destroy;
}

static void
antlr_object_init(AntlrObject *object)
{
    object->ref.count = 1;
}

void antlr_object_ref(AntlrObject *object)
{
    object->ref.count++;
}

void antlr_object_unref(AntlrObject *object)
{
    object->ref.count--;
    if (object->ref.count<1) {
        antlr_object_destroy(object);
    }
}

AntlrPtr
antlr_object_new(AntlrType type)
{
    AntlrObjectClass *klass = antlr_type_get_class()[type];

    AntlrPtr object = klass->construct();
    klass->init(object);

    return object;
}

void
antlr_object_destroy(AntlrObject *object)
{
    AntlrObjectClass *klass = antlr_type_get_class()[object->type];

    klass->destroy(object);
}
