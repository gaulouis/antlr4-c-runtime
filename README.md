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
