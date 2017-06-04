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
    AntlrDocument *doc;
    AntlrElement *root;
    
    doc = antlr_read_file("script.sql", SQL_TYPE_PARSER, &error);
    if (NULL==doc) {
        printf("Error: %s\n", error->message);
        antlr_free(error);
        return 1;// exit
    }

    /*Get the root element node */
    root = antlr_get_root_node(doc);
    antlr_print_context_names(root);
    
    // Free memory
    antlr_free(doc);// destroy 

    return 0;
}
```
