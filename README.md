1. Based on my program the value in child process is 300 and the value in parent is 400.
2. Both of them can access. For concurrency we don't know which one will finish first so the order of the string in the output might vary. 
3. Used semaphore which send out signal to determine which process run first. 
4. The reason there are so many variants of the exec() call is to provide different ways to specify the arguments and environment for the new process, catering to different use cases and programming preferences.
5. The parent process's wait() call returns the PID of the terminated child. If I wait in the child, the parent will process first, and the child will wait until parent is done.
6. Waitpid is useful when there are multiple children and you want to designate which one to wait.
7. I'm not able to print from the child process after calling STDOUT_FILENO.
8. see code.