### Shared libraries and static libraries

#### Shared libraries
* Linux: .so
* Windows: .dll
* macOS: .dylib

All the code relating to the library is in this file, and it is referenced by programs using it at run-time.

A program using a shared library only makes reference to the code that it uses in the shared library.

Shared libraries reduce the amount of code that is duplicated in each program that makes use of the library, keeping the binaries small.

It also allows you to replace the shared object with one that is functionally equivalent, but may have added performance benefits without needing to recompile the program that makes use of it.

Shared libraries will, however have a small additional cost for the execution of the functions as well as a run-time loading cost as all the symbols in the library need to be connected to the things they use.

Additionally, shared libraries can be loaded into an application at run-time, which is the general mechanism for implementing binary plug-in systems.

Example:

* Compile the library source code into position-independent code [PIC](https://en.wikipedia.org/wiki/Position-independent_code):

```
gcc -c -Wall -Werror -fpic calc.c

```

* Turn this new object file into a shared library named _libcalc.so_ :

```
gcc -shared calc.o -o libcalc.so
```

* Compile the _main.c_ and link it with _libcalc.so_ and try to run it:

```
gcc -L. -Wall main.c -lcalc -o mycalc
./mycalc
./mycalc: error while loading shared libraries:
libcalc.so: cannot open shared object file: No such file or directory
```
The loader can not find the shared library because it is not located in a standard location, so we need to give some instruction to the loader:

* In Linux, the environment variable LD_LIBRARY_PATH is a colon-separated set of directories where libraries should be searched for first, before the standard set of directories:

```
LD_LIBRARY_PATH=/path/to/the/lib/folder/:$LD_LIBRARY_PATH
./mycalc
It works!
```


#### Static libraries
* Linux/macOS: .a
* Windows: .lib

All the code relating to the library is in this file, and it is directly linked into the program at compile time.

A program using a static library takes copies of the code that it uses from the static library and makes it part of the program (Windows also has .lib files which are used to reference .dll files, but they act the same way as the first one).

Static libraries increase the overall size of the binary, but it means that you don't need to carry along a copy of the library that is being used.

As the code is connected at compile time there are not any additional run-time loading costs. The code is simply there.
