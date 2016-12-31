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

#ifndef __ANTLR_TYPE_H__
#define __ANTLR_TYPE_H__

#include <stdlib.h>
#include <string.h>

#define ANTLR_TYPE_NONE          antlr_none_get_type()


typedef void*                    AntlrPtr;
typedef enum   _AntlrType        AntlrType;// put it in types.h ?


enum _AntlrType {
    AntlrNoneType = 0,// Type 0 is not valid

    // base object
    AntlrObjectType,

    // concret object
    AntlrInputStreamType,
    AntlrFileStreamType,

    // reserved for extention user
    AntlrTypes
};

AntlrType antlr_none_get_type(void);
AntlrPtr* antlr_type_get_class();
int       antlr_type_get_class_size(AntlrType type);
void      antlr_type_set_class_size(AntlrType type, int size);

unsigned int*   antlr_type_get_instance_count();
void            antlr_type_check_instance();

#endif // __ANTLR_TYPE_H__
