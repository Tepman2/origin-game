#include "ThreadSingle.h"

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
    )
{
    int ret_val;
    pthread_attr_t attr;
    pthread_t * tmp_thread;

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
        thrd = tmp_thread;
        return( 0 );
        }
}
