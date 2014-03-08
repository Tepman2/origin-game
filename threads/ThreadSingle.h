#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>


/********************************************************************
* @brief Makes one single thread, returned through the first parameter.
*
* @param thrd The thread created
* @param func The function run by the thread
* @param args The arguments to the function run by the thread
*
* @return Returns 0 on success, -1 otherwise
********************************************************************/
int makeOneThread
    (
    pthread_t * thrd,
    void ( *func ),
    void * args
    );
