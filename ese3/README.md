# Related bash commands:

---

**ps**

Report a snapshot of the current processes.

---

**ps -x**

Adding the "x" option tells ps to show all of our processes regardless of what terminal (if any) they are controlled by.

---

From **man ps**:

```
PROCESS STATE CODES
       Here are the different values that the s, stat and state output specifiers (header "STAT" or "S") will display to describe the state of a process:

               D    uninterruptible sleep (usually IO)
               R    running or runnable (on run queue)
               S    interruptible sleep (waiting for an event to complete)
               T    stopped by job control signal
               t    stopped by debugger during the tracing
               W    paging (not valid since the 2.6.xx kernel)
               X    dead (should never be seen)
               Z    defunct ("zombie") process, terminated but not reaped by its parent

       For BSD formats and when the stat keyword is used, additional characters may be displayed:

               <    high-priority (not nice to other users)
               N    low-priority (nice to other users)
               L    has pages locked into memory (for real-time and custom IO)
               s    is a session leader
               l    is multi-threaded (using CLONE_THREAD, like NPTL pthreads do)
               +    is in the foreground process group
```
---


**ps -aux**

```
RSS       resident set size, the non-swapped physical memory that a task has used (in kiloBytes)
VSZ       virtual memory size of the process in KiB (1024-byte units)
```
