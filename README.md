# ANTLR 4 Runtime C implementation

+ CMake build system
+ No dependencies
+ Static OOP mecanisme (morphing, heritage, interface)

## Install:
```
$ cd ~/local
$ git clone https://github.com/gaulouis/antlr4-c-runtime.git
$ mkdir antlr4-c-runtime-install
$ mkdir antlr4-c-runtime-build-Release
$ mkdir antlr4-c-runtime-build-Debug
$ cd antlr4-c-runtime-build-Debug
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=~/local/antlr4-c-runtime-install -DCMAKE_BUILD_TYPE=Debug -DENABLE_DEBUG:BOOL=1 ../antlr4-c-runtime
$ ANTLR_DEBUG=all && ./src/demo/antlr4-c-demo
```

## TODO:
+ Check the CMAKE_BUILD_TYPE to enable AntlrObjectClass.name
+ Create a gdb pretty print python script
