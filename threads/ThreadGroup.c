#include "ThreadGroup.h"
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
    void * args
    )
{
    int ret_val;
    pthread_attr_t attr;
    pthread_t * tmp_thread;

    if( threadGroup->numThreads == MAX_NUM_THREADS )
        {
        return( -1 );
        }

    /****************************************************************
    Set up basic thread attributes
    ****************************************************************/
    pthread_attr_init( &attr );
    pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_JOINABLE );

    /****************************************************************
    Create the thread
    ****************************************************************/
    ret_val = pthread_create( tmp_thread, &attr, func, args );
    if( ret_val < 0 )
        {
        perror( strerror( ret_val ) );

        return( -1 );
        }
    else
        {
        group->threads[ group->numThreads ] = tmp_thread;
        group->numThreads++;
        return( 0 );
        }
}
