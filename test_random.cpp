/*
    g++ `pkg-config --cflags opencv` -o test_random test_random.cpp `pkg-config --libs opencv`编译添加opencv库的文件；
    g++ test_random.cpp -o test_random 编译正常文件
    测试使用cpp文件实现一维、二维随机数组，包括使用正则化函数，并测试使用时间
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <sys/time.h>
#include <numeric>
#include <algorithm>
// #include <opencv2/opencv.hpp>
#define N  999

// using namespace cv;
using namespace std;
int a = 3;

void getWeightRandom(std::vector<std::vector<double>> &data, double data_number)
{   
    for (int i=0;i<data_number;i++)
    {
        srand((unsigned)time(NULL)); //用当前系统时间设置种子
        std::vector<double> temp_a(4500);
        
        for(int j=0;j<4500;j++)
        {
            temp_a.push_back(rand());
            
        }
        data.push_back(temp_a);
    }
}

void get_randVec(std::vector<double> &temp_a)
{
    srand((unsigned)time(NULL)); //用当前系统时间设置种子
    // std::vector<double> temp_a(4500);
    
    for(int i=0;i<4500;i++)
    {
        temp_a[i]=rand();
        
    }
}

void sparse_activation(std::vector<double> data, double &tmp_value)
{
    sort(data.begin(), data.end());
    tmp_value = data[data.size()-a];
    std::cout <<"tmp_value" << tmp_value << std::endl;
}

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::cout << "start timestamp is: " << tv.tv_sec << "." << tv.tv_usec<< std::endl;
    int placecell_number = 4096;
    std::vector<std::vector<double>> hebbian_weight;
    
    for (int i=0;i<placecell_number;i++)
    {
        srand((unsigned)time(NULL)); //用当前系统时间设置种子
        std::vector<double> temp_a(4500);
        
        for(int j=0;j<4500;j++)
        {
            double a = rand()% (N + 1) / (float)(N + 1);
            temp_a.push_back(a );
            std::cout << "rand a is :" <<a <<std::endl;
            
        }
        // normalize(temp_a, temp_a,1,0,NORM_L2);
        hebbian_weight.push_back(temp_a);
    }

    // getWeightRandom(hebbian_weight, placecell_number);

    
    // double theta_a = 0;
    // vector<double> test_data={2,7,3,4,6};
    // sparse_activation(test_data,theta_a);
    // std::cout << test_data[4] << std::endl;
    // std::cout << theta_a << std::endl;

    
    return 0;
}

