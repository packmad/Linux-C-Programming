[Valgrind](http://valgrind.org/) is an instrumentation framework for building dynamic analysis tools. 

There are Valgrind tools that can automatically detect many memory management and threading bugs, and profile your programs in detail.

Those examples show: 

* [memcheck](http://valgrind.org/docs/manual/mc-manual.html), a memory error detector;
* [helgrind](http://valgrind.org/docs/manual/hg-manual.html), detects synchronisation errors in C/C++ programs that use the POSIX pthreads threading primitives;
* [callgrind](http://valgrind.org/docs/manual/hg-manual.html), a profiling tool that records the call history among functions in a program's run as a call-graph.


Recommended readings:
* [Guide to valgrind](https://web.stanford.edu/class/cs107/guide/valgrind.html)
* [Guide to callgrind](https://web.stanford.edu/class/cs107/guide/callgrind.html)
