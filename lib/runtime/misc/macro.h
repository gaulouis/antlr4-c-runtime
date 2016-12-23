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

#ifndef __ANTLR_MACRO_H__
#define __ANTLR_MACRO_H__


#ifdef  __cplusplus
#   define ANTLR_BEGIN_DECLS  extern "C" {
#   define ANTLR_END_DECLS    }
#else
#   define ANTLR_BEGIN_DECLS
#   define ANTLR_END_DECLS
#endif

#define N_ELEMENTS(array) (sizeof(array)/sizeof((array)[0]))

#if defined(ENABLE_DEBUG) && ENABLE_DEBUG
#define _ANTLR_DECLAR_TYPE_EXTENDED_CLASS_DEBUG(TypeName, type_name) \
        static char *type_name##_class_name = #TypeName;
#define _ANTLR_DEFINE_TYPE_EXTENDED_CLASS_DEBUG(type_name) \
        ANTLR_OBJECT_CLASS(klass)->name = type_name##_class_name;
#else
#define _ANTLR_DECLAR_TYPE_EXTENDED_CLASS_DEBUG(TypeName, type_name)
#define _ANTLR_DEFINE_TYPE_EXTENDED_CLASS_DEBUG(type_name)
#endif

#define _IMEMBER(T) T##Member
#define _IFACE(T) T##IFace
#define ANTLR_IMPLEMENT_INTERFACE(TYPE_IFACE, iface_init)\
    iface_init(&((_IFACE(TYPE_IFACE)*)klass)->_IMEMBER(TYPE_IFACE));

#define ANTLR_DEFINE_TYPE(TN, t_n, T_P)			    ANTLR_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, 0, {})
#define ANTLR_DEFINE_TYPE_WITH_CODE(TN, t_n, T_P, _C_)	    _ANTLR_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, 0) {_C_;} _ANTLR_DEFINE_TYPE_EXTENDED_END(TN, t_n, T_P)

#define ANTLR_DEFINE_TYPE_EXTENDED(TN, t_n, T_P, _f_, _C_)	    _ANTLR_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, _f_) {_C_;} _ANTLR_DEFINE_TYPE_EXTENDED_END(TN, t_n, T_P)


#define _ANTLR_DEFINE_TYPE_EXTENDED_BEGIN(TypeName, type_name, TYPE_PARENT, _f_) \
_ANTLR_DECLAR_TYPE_EXTENDED_CLASS_DEBUG(TypeName, type_name) \
static void     type_name##_init              (TypeName        *self); \
static void     type_name##_class_init        (TypeName##Class *klass); \
static AntlrObjectClass* type_name##_parent_class = 0; \
\
static void \
type_name##_internal_init(AntlrObject *object) \
{ \
    AntlrType parent_type = TYPE_PARENT; \
    if (parent_type>AntlrNoneType) { \
        ANTLR_OBJECT_CLASS(type_name##_parent_class)->init(object); \
    } \
    type_name##_init((TypeName*)object); \
} \
\
static AntlrPtr \
type_name##_internal_construct(void) \
{ \
    AntlrPtr object = malloc(sizeof(TypeName)); \
    ANTLR_OBJECT(object)->type = TypeName##Type; \
    return object; \
} \
\
static void \
type_name##_class_registry(void) \
{ \
    AntlrType type = TypeName##Type; \
    AntlrType parent_type = TYPE_PARENT; \
    AntlrPtr* antlr_class = antlr_type_get_class(); \
    TypeName##Class* klass = (TypeName##Class*)antlr_class[type]; \
    if (!klass) { \
        klass = (TypeName##Class*) malloc(sizeof(TypeName##Class)); \
        antlr_type_set_class_size(TypeName##Type, sizeof(TypeName##Class)); \
        antlr_class[type] = ANTLR_OBJECT_CLASS(klass); \
        \
        type_name##_parent_class = antlr_class[parent_type]; \
        int size = antlr_type_get_class_size(parent_type); \
        memcpy(klass, type_name##_parent_class, size); \
        \
        _ANTLR_DEFINE_TYPE_EXTENDED_CLASS_DEBUG(type_name) \
        \
        ANTLR_OBJECT_CLASS(klass)->parent_type = parent_type; \
        ANTLR_OBJECT_CLASS(klass)->construct = type_name##_internal_construct; \
        ANTLR_OBJECT_CLASS(klass)->init = type_name##_internal_init; \
        /*ANTLR_OBJECT_CLASS(klass)->destroy = type_name##_internal_destroy;*/ \
        type_name##_class_init(klass);

#define _ANTLR_DEFINE_TYPE_EXTENDED_END(TypeName, type_name, TYPE_PARENT)	\
    } \
} \
\
AntlrType \
type_name##_get_type(void) \
{ \
    type_name##_class_registry(); \
    return TypeName##Type; \
}


#endif // __ANTLR_MACRO_H__
