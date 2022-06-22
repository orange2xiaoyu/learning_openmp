#include <iostream>
#include <omp.h>

int main(int argc,char* argv[])
{
    int thread_count = atoi(argv[1]);
    int j = 2;
    #pragma omp parallel for num_threads(thread_count) lastprivate(j)
    for(int i=0;i<8;i++)
    {
        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();
        j = my_rank;
        printf("hello from thread %d of %d\n",my_rank,thread_count);
    }

    printf("j = %d\n",j);
    return 0;
}