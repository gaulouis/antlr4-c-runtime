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

#ifndef __ANTLR_FILE_STREAM_H__
#define __ANTLR_FILE_STREAM_H__


ANTLR_BEGIN_DECLS

#define ANTLR_FILE_STREAM(obj)           ((AntlrFileStream*)obj)
#define ANTLR_TYPE_FILE_STREAM           (antlr_file_stream_get_type())
#define ANTLR_FILE_STREAM_CLASS(klass)   ((AntlrFileStreamClass*)klass)
#define ANTLR_FILE_STREAM_GET_CLASS(obj) ((AntlrFileStreamClass*)(antlr_type_get_class()[ANTLR_TYPE_FILE_STREAM]))


typedef struct AntlrFileStream      AntlrFileStream;//!< AntlrFileStream type
typedef struct _AntlrFileStreamClass AntlrFileStreamClass;

/*!
 *
 * \brief The AntlrFileStream object
 *
 * This is an AntlrFileStream that is loaded from a file all at once when you
 * construct the object.
 *
 */

/*!
 * AntlrFileStream class.
 * \extends AntlrInputStream
 */
struct AntlrFileStream
{
    AntlrInputStream parent_instance;//!< \protected Base class.
};

/*!
 * \struct _AntlrFileStreamClass
 * \brief The vtable of AntlrFileStream
 *
 * \relates AntlrFileStream
 */
struct _AntlrFileStreamClass
{
    AntlrInputStreamClass parent_class;//!< \private Base class.
};

/*!
 * \brief Get the AntlrType of AntlrFileStream object
 * Note than it is by this function than AntlrFileStream vtable has initialized
 * \relates AntlrFileStream
 */
AntlrType antlr_file_stream_get_type(void);

/*!
 * \brief Create a new AntlrFileStream instance.
 * \return Output that is extra useful
 *
 * This method does unbelievably useful things.  
 * And returns exceptionally useful results.
 * Use it everyday with good health.
 *
 * \relates AntlrFileStream
 */
AntlrFileStream *antlr_file_stream_new(void);

ANTLR_END_DECLS

#endif // __ANTLR_FILE_STREAM_H__
