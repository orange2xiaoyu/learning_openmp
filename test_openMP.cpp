#include <iostream>
#include <time.h>
#include <omp.h>

void test()
{
    int a= 0;
    for (int i=0;i<1000000;i++)
        a++;
    std::cout << "a is "<< a << std::endl;
}


int main()
{
    clock_t t1 = clock();
    #pragma omp parallel for
    for (int i=0;i<8;i++)
    {
        test();
    }
    clock_t t2 = clock();
    std::cout << "time is "<< t2-t1 <<std::endl;
}
