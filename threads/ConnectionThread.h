#include <boost/thread.hpp>
void thread_func( void );

class ConnectionThreads: public boost::thread_group
{
    public:
        boost::thread * ConnectionThreads::make_new_thread( void *( thread_func ) );
}
