# learning_openmp

openMP是通过线程实现并行化，统一访问内存。

Fork(派生)：主线程创建一组并行化执行的线程；

Join(合并)：当线程完成工作，他们会进行同步与终止，只剩下主线程。

## openMP parallel

    #pragma omp parallel num_threads(thread_count)           //thread_count线程数量，自定义设定
    my_rank = omp_get_thread_num();          //获取线程id,若自定义4个线程，则my_rank可以为0，1，2，3
    my_num = omp_get_num_threads();          //获取线程的数量，若自定义为4个线程，则my_num为4

## openMP for
+ 使用openmp parallel for需要满足的条件：
    - 循环的迭代器必须是可计算的，并且在执行前需要确定迭代次数；
    - 循环的代码块不能包含break，retuen，以及exit等；
    - 循环的代码不能使用goto跳出循环；
    - 迭代器只能被for语句中的增量表达式修改（在计算过程中，将n个过程分为num_threads个线程均匀计算，比如迭代1000次，有4个线程，则将1000次循环分为4个部分，分别对应4个线程一一对应计算）

在该过程中存在数据依赖性，具体表现为在该循环中的计算依赖一个或者更多个先前的迭代结果。

注意：在该过程重要尽量避免数据依赖性的存在。

    #pragma omp parallel for
    for(int i=1;i<800;i++)              //在接下来的for循环中，会使用并行的方式执行
        runcode();

## openMP private variables

直接告诉编译器去使得共享变量作为每个线程中的私有变量。

+ 为了避免不同的线程同时对同一个变量进行操作，我们设置了私有变量，特点包括：
    - 每一个线程都是拥有独自的该变量的副本；
    - 若j被定义为私有变量，那么在for循环中，所有线程不能访问其他的j；
    - 所有线程的私有变量不会使用先前的定义；
    - 所有线程不饿能给共享的j赋值。


### Firstprivate

告诉编译器私有变量在第一个循环会继承共享变量j的值，并且只会在每个线程的第一个循环中继承。

    #pragma omp parallel for num_threads(thread_count) firstprivate(j)

### Lastprivate

在最后一个循环出去的时候，最后一个线程用私有变量的值替代共享变量的值。

    #pragma omp parallel for num_threads(thread_count) lastprivate(j)


# test_random
实现一维、二维随机数组，包括使用正则化函数，并测试使用时间