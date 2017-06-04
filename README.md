# ANTLR 4 Runtime C implementation

+ CMake build system
+ No dependencies
+ Static OOP mecanisme (morphing, heritage, interface)

## Install:
```
$ cd ~/local
$ git clone https://github.com/gaulouis/antlr4-c-runtime.git
$ mkdir antlr4-c-runtime-install
$ mkdir antlr4-c-runtime-build-Debug
$ cd antlr4-c-runtime-build-Debug
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=~/local/antlr4-c-runtime-install -DCMAKE_BUILD_TYPE:STRING=Debug -DENABLE_DEBUG:BOOL=1 ../antlr4-c-runtime
$ make
$ make doc
$ ./src/demo/antlr4-c-demo
$ export ANTLR_DEBUG=all
$ ./src/demo/antlr4-c-demo
$ make install
```

## TODO:
+ Create a gdb pretty print python script
+ Implementation of antlr
+ Implementation Unit tests fonctionnal tests


## Simple antlr4-c-runtime example:
```C
#include <antlr/runtime.h>
#include "sql-antlr.h" // SqlLexer, SqlParser, SqlContextStatement, SqlListener

int
main (int argc, char *argv[])
{
    AntlrError *error = NULL;
    AntlrParser *parser;
    AntlrContextStatement *stat_context = NULL;
    
    const char *filename = "/home/user/local/src/antlr-c-runtime/share/scripts/test.sql";    
    parser = sql_parser_new_from_filename(filename, &error);
    if (NULL==parser) {
        printf("Error: %s\n", error->message);
        antlr_object_unref(error);
        return 1;// exit
    }

    // Specify our entry point
    stat_context = sql_parser_parse_statement(SQL_PARSER(parser), &error);
    if (!stat_context) {
        printf("Error: %s\n", error->message);
        antlr_object_unref(error);
        return 1;// exit
    }

    // Free memory
    antlr_object_unref(parser);
    antlr_object_unref(stat_context);

    return 0;
}
```
