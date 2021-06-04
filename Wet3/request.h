#ifndef __REQUEST_H__
#include "queue.h"
typedef struct thread_statistics_t
{
    unsigned int thread_id;
    unsigned int thread_count;
    unsigned int thread_static;
    unsigned int thread_dynamic;

} thread_statistics;

void requestHandle(int fd,thread_statistics* thread_statistics_p,Connection con);

#endif
