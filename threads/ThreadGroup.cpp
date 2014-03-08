#include "ThreadGroup.h"

/********************************************************************
*   PROCEDURE NAME: makeNewThread - makes a new thread to add to
*                                   the connection threads
*
*   @param threadFunc The function the thread will be calling to do
*                     its work
*
*   NOTE: This function may be able to be replaced with a generic
*   function that could be used for all connections to the server.
*
********************************************************************/
boost::thread * ThreadGroup::makeNewThread( Callable threadFunc )
{
    boost::thread tempThread( threadFunc );
    this.add_thread( &tempThread);

    /****************************************************************
    Return the address of the created thread.
    ****************************************************************/
    return( &tempThread );
}

