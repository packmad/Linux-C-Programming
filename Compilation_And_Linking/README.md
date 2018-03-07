Compiling a C program is a multi-stage process:

* **Preprocessing**
```
gcc -E hello_world.c > preprocessed_hello_world.c
```
  * Input: source code files (.c, .cpp)
  * Output: source code


* **Compilation**
```
gcc -S hello_world.c
```
  * Input: source code
  * Output: assembler source code (.s)
    * assembly instructions specific to the target processor architecture source


* **Assembly**
```
gcc -c hello_world.c
```
    * Input: assembler source code (.s)
    * Output: object code (.o)
      * [Extensible Linking Format](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) relocatable
      * machine code instructions but some pieces of the program are out of order or missing

* **Linking**
```
gcc hello_world.c
```
  * Input: object code (.o)
  * Output: executable program
     * [Extensible Linking Format](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) executable


### Static and Dynamic linking

The compiler automatically invokes the linker as the last step in compiling a program.

The linker inserts code (or maps in shared libraries) to resolve program library references, and/or combines object modules into an executable image suitable for loading into memory.

On Unix-like systems, the linker is typically invoked with the `ls` command (gcc uses `collect2` that calls `ld` in the end).

**Static linking** is the result of the linker copying all library routines used in the program into the executable image. This may require more disk space and memory than dynamic linking, but is both faster and more portable, since it does not require the presence of the library on the system where it is run.

**Dynamic linking** is accomplished by placing the name of a sharable library in the executable image. Actual linking with the library routines does not occur until the image is run, when both the executable and the library are placed in memory. An advantage of dynamic linking is that multiple programs can share a single copy of the library.


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


#### Static libraries
* Linux/macOS: .a
* Windows: .lib

All the code relating to the library is in this file, and it is directly linked into the program at compile time.

A program using a static library takes copies of the code that it uses from the static library and makes it part of the program (Windows also has .lib files which are used to reference .dll files, but they act the same way as the first one).

Static libraries increase the overall size of the binary, but it means that you don't need to carry along a copy of the library that is being used.

As the code is connected at compile time there are not any additional run-time loading costs. The code is simply there.
