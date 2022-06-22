#include <iostream>
#include <omp.h>


int main(int argc,char* argv[])
{
    int thread_count = atoi(argv[1]);
    int my_rank = omp_get_thread_num();
    // int thread_count = omp_get_num_threads();
    double a[1000];
    double b[1000];
    for(int i=0;i<1000;i++)
    {
        a[i] = i;
        b[i] = 1000-i;
    }
    double s[1000];
    double d[100];
    #pragma omp parallel for num_threads(thread_count)
    for(int i=0;i<1000;i++)
    {
        s[i] = a[i] + b[i];
        for(int j=0;j<100;j++)
        {
            d[j] = s[j];
            // printf("hello from thread %d of %d in 2 for.\n",my_rank,thread_count);
        }
        printf("hello from thread %d of %d in 1 for.\n",my_rank,thread_count);
        // if(i == 512)
        // {
        //     printf("%d to 512\n",omp_get_thread_num());
        // }
        // if(i == 100)
        // {
        //     printf("%d to 100\n",omp_get_thread_num());
        // }
    }
    
    
    return 0;
}