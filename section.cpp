#include <iostream>
#include <omp.h>

int main(int argc,char* argv[])
{
    int thread_count = atoi(argv[1]);
    #pragma omp parallel num_threads(thread_count)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                int my_rank = omp_get_thread_num();
                int thread_count = omp_get_num_threads();
                printf("hello from thread %d of %d in section 1.\n",my_rank,thread_count);
            }
            #pragma omp section
            {
                int my_rank = omp_get_thread_num();
                int thread_count = omp_get_num_threads();
                printf("hello from thread %d of %d in section 2.\n",my_rank,thread_count);
            }
            #pragma omp section
            {
                int my_rank = omp_get_thread_num();
                int thread_count = omp_get_num_threads();
                printf("hello from thread %d of %d in section 3.\n",my_rank,thread_count);
            }
            #pragma omp section
            {
                int my_rank = omp_get_thread_num();
                int thread_count = omp_get_num_threads();
                printf("hello from thread %d of %d in section 4.\n",my_rank,thread_count);
            }

        }
    }
    return 0;
}