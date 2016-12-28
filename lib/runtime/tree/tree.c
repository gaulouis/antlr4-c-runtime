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

#include "tree.h"




//ANTLR_DEFINE_TYPE(AntlrTree, antlr_tree, ANTLR_TYPE_OBJECT)
ANTLR_DEFINE_TYPE (AntlrTree, antlr_tree, ANTLR_TYPE_OBJECT)

#define parent_class antlr_tree_parent_class
static void
antlr_tree_class_object_destroy(AntlrObject *object)
{
    ANTLR_OBJECT_CLASS(parent_class)->destroy(object);
}

static void
antlr_tree_class_init(AntlrTreeClass *klass)
{
    ANTLR_OBJECT_CLASS(klass)->destroy = antlr_tree_class_object_destroy;
}


void
antlr_tree_init(AntlrTree *self)
{
}

AntlrTree*
antlr_tree_new(void)
{
    AntlrTree *stream = antlr_object_new(ANTLR_TYPE_TREE);
    return stream;
}

