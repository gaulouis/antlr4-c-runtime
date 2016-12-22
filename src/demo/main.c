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

#include <stdio.h>

#include <Config.h>

//#include <antlr/runtime.h>
#include "runtime.h"


/*
Let create a custom Parser (option SuperClass)

--------
// my-types.h

enum _MyType {
    MyNoneType = AntlrTypes,

    MyParserType,// SuperClass

    MyTypes
};

--------
// my-parser.h

typedef struct _MyParser {
    int member;
} MyParser;

typedef struct _MyParserClass {
    void (*method)(MyParser *self, ...);
} MyParserClass;

--------
// my-parser.c

ANTLR_DEFINE_TYPE(MyParser, my_parser, ANTLR_TYPE_PARSER)

my_parser_class_init(MyParserClass *klass) {
    ANTLR_OBJECT_CLASS(klass)->method = override_method;
    //...
    ANTLR_PARSER_CLASS(klass)->method = override_method;
    klass->method = my_virtual_method;
}

my_parser_init(MyParser *self) {
    ANTLR_OBJECT(self)->ref.count;// Ref counting initialized at 1 by antlr_object_init
    //...
    ANTLR_PARSER(self)->member;// initialized by antlr_recognizer_init
    self->member = 0;
}

MyParser*
my_parser_new() {
    return antlr_object_new(MY_TYPE_PARSER);
}

*/

int main(int argc, char *argv[])
{
    AntlrFileStream *stream = antlr_file_stream_new();
    antlr_int_stream_interface_consume(ANTLR_INT_STREAM_INTERFACE(stream));

    antlr_object_unref(ANTLR_OBJECT(stream));

    printf("Kick starter!\n");
    printf("[X] chaining constructor/initializer!\n");
    printf("[X] chaining destroy!\n");
    printf("[X] call interface!\n");
    printf("[X] ref counting!\n");
    printf("[ ] TODO: end-user custom class\n");// in misc/macro.h
                                                // modify ANTLR_DEFINE_TYPE _registry()
                                                // to get static AntlrPtr antlr_type_class[] dynamic
                                                // if (AntlrNoneType<type && type<AntlrTypes)
                                                //    use static array
                                                // else
                                                //    use dynamic array
    printf("[ ] TODO: Copy/past implementation from antlr4-GLib\n");
    return 0;
}

