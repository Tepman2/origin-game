#include "thread.h"

/********************************************************************
*   PROCEDURE NAME: make_new_thread - makes a new thread to add to
*                                     the connection threads
*
*   @param thread_func The function the thread will be calling to do
*                      its work
*
*   NOTE: This function may be able to be replaced with a generic
*   function that could be used for all connections to the server.
*
********************************************************************/
boost::thread * ConnectionThreads::make_new_thread( void * ( thread_func )( void ) )
{
    boost::thread *temp_thread = boost::thread_group.create_thread( thread_func );
    this.add_thread( temp_thread );

    /****************************************************************
    Return the address of the created thread.
    ****************************************************************/
    return( temp_thread );
}
