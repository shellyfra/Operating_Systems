#ifndef __REQUEST_H__
#include "queue.h"

typedef struct thread_statistics_t
{
    int thread_id;
    int thread_count;
    int thread_static;
    int thread_dynamic;

} thread_statistics;
typedef struct thread_and_stat_t
{
    pthread_t* thread;
    thread_statistics* stat;
} thread_and_stat;

void requestHandle(int fd,thread_statistics* thread_statistics_p,Connection con);

#endif
