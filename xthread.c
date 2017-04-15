#include "types.h"
#include "user.h"
#include "xthread.h"


void xthread_create(int * tid, void * (* start_routine)(void *), void * arg)
{
    // add your implementation here ...
  void *stack = malloc(4096);
  int temp_tid=0;  
  temp_tid  = clone(start_routine,stack,arg);
  *tid = temp_tid;
}


void xthread_exit(void * ret_val_p)
{
    // add your implementation here ...
    thread_exit(ret_val_p);    
}


void xthread_join(int tid, void ** retval)
{
    // add your implementation here ...
void * stack;
join(tid,retval,&stack);
free(stack);
}
