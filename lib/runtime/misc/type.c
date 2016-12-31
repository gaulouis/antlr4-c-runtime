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

// FIXME: Warning how to initialize to 0 (make it dynamic ?)
static AntlrPtr antlr_type_class[/*AntlrTypes*/] = {
    0, //AntlrNoneClass          void
    0, //AntlrObjectClass        uninitializer
    0, //AntlrInputStreamClass   uninitializer
    0, //AntlrFileStreamClass    uninitializer
    0,
    0
};
static unsigned int antlr_type_instance_count[N_ELEMENTS(antlr_type_class)] = {
    0, //AntlrNoneClass          initializer to zero
    0, //AntlrObjectClass        initializer to zero
    0, //AntlrInputStreamClass   initializer to zero
    0, //AntlrFileStreamClass    initializer to zero
    0,
    0
};

static int antlr_class_size[N_ELEMENTS(antlr_type_class)] = {0};// AntlrNoneClass is 0


AntlrType
antlr_none_get_type(void)
{
    return AntlrNoneType;
}

AntlrPtr*
antlr_type_get_class()
{
    return antlr_type_class;
}

int
antlr_type_get_class_size(AntlrType type)
{
    return antlr_class_size[type];
}

void
antlr_type_set_class_size(AntlrType type, int size)
{
    antlr_class_size[type] = size;
}

unsigned int*
antlr_type_get_instance_count()
{
    return antlr_type_instance_count;
}
#include <stdio.h>
#include "object.h"
void
antlr_type_check_instance()
{
    int i;
    for (i=0; i<N_ELEMENTS(antlr_type_instance_count); i++) {
        unsigned int instance_count = antlr_type_instance_count[i];
        if (instance_count) {
            AntlrObjectClass *klass = antlr_type_class[i];
            printf("%s has %d instance\n", klass->name, instance_count);
        }
    }
}


