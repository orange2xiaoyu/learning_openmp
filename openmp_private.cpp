#include <iostream>
#include <omp.h>


int main(int argc,char* argv[])
{
    int thread_count = atoi(argv[1]);
    double a[1000];
    double b[1000];
    double c[1000];
    double d[1000];
    double tmp;
    for(int i=0;i<1000;i++)
    {
        a[i] = i;
        b[i] = 1000-i;
    }
    double s[1000];
    #pragma omp parallel for num_threads(thread_count) private(tmp)
    //并行计算
    for(int i=0;i<1000;i++)
    {
        tmp = a[i]/b[i];          //同一时刻不同线程同时对tmp进行操作，导致并行计算和串行计算结果不一致
        c[i] = tmp*tmp;                  
    }

    //串行计算
    for(int i=0;i<1000;i++)
    {
        tmp = a[i]/b[i];
        d[i] = tmp*tmp;
        if(c[i] != d[i])
        {
            printf("something wroing!!\n");
        }
    }
    
    
    return 0;
}