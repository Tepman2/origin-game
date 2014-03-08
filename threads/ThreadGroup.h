#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/**
* The maximum number of threads in a group. This can be increased
* later.
*/
#define MAX_NUM_THREADS 255

/**
* The structure for a thread group. Contains a member for checking if
* all threads are joined.
*/
typedef struct
{
    pthread_t * threads[ MAX_NUM_THREADS ];
    unsigned char numThreads;
    unsigned char allJoined;
}threadGroup;


/********************************************************************
*
* @brief Adds a new thread to the group
*
* @param group The thread group to add to
* @param func The function the new thread should use to do the work
* @param args The arguments to the function
*
********************************************************************/
int addNewThreadToGroup
    (
    threadGroup * group,
    void ( *func ),
    void* args
    );

