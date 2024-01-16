#include<iostream>
#include<vector>

//测试数据的初始化方式
void test_InitParam(){
    std::cout <<  " hello world" << std::endl;
    int a1;
    int a2{};
    int arr[10]{};
    char tmp{};
    char name[15]{};
    std::cout << name << std::endl;
    std::cout << tmp;
}

//测试结构体初始化方式
struct Point1{
    int x{};
    int y{};
};

struct Point2{
    int x;
    int y;
}
void test_InitStruct(int x, int y){
    Point point(std::move(x), std::move(y));
    std::cout << point.x << std::endl;
    std::cout << point.y << std::endl;

    // std::vector<Point> points;
    // for(int i=0; i<10; ++i){
    //     points.push_back(Point(i,i+1));
    // }

    // for(auto &p : points){
    //     std::cout << p.x << " " << p.y << std::endl;
    // }
}

int main()
{
    //test_InitParam();
    test_InitStruct(100,200);
    return 0;
}