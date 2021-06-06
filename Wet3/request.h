#ifndef __REQUEST_H__
#include "queue.h"
typedef struct thread_statistics_t
{
    int thread_id;
    int thread_count;
    int thread_static;
    int thread_dynamic;

} thread_statistics;

void requestHandle(int fd,thread_statistics* thread_statistics_p,Connection con);

#endif
