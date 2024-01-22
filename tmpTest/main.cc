#include<iostream>
#include<vector>
#include<chrono>

// //测试数据的初始化方式
// void test_InitParam(){
//     std::cout <<  " hello world" << std::endl;
//     int a1;
//     int a2{};
//     int arr[10]{};
//     char tmp{};
//     char name[15]{};
//     std::cout << name << std::endl;
//     std::cout << tmp;
// }

// //测试结构体初始化方式
// struct Point1{
//     int x{};
//     int y{};
// };

// struct Point2{
//     int x;
//     int y;
// }
// void test_InitStruct(int x, int y){
//     Point point(std::move(x), std::move(y));
//     std::cout << point.x << std::endl;
//     std::cout << point.y << std::endl;

//     // std::vector<Point> points;
//     // for(int i=0; i<10; ++i){
//     //     points.push_back(Point(i,i+1));
//     // }

//     // for(auto &p : points){
//     //     std::cout << p.x << " " << p.y << std::endl;
//     // }
// }

void test_chrono(){
    // 获取当前时间点
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    //转换为自Epoch以来的时间长度
    decltype(now.time_since_epoch()) duration = now.time_since_epoch();
    //std::chrono::duration<std::chrono::microseconds> duration2 = now.time_since_epoch();

    std::cout << typeid(duration).name() << std::endl;
    //std::cout << typeid(duration2).name() << std::endl;

    // // 将时间长度转换为秒
    // std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();

    // std::cout << seconds << std::endl;

    // // 输出时间戳（秒）
    // std::cout << "Seconds since January 1, 1970: " << seconds << std::endl;
    // unsigned int timestamp = std::chrono::system_clock::now().time_since_epoch().count();
    // std::cout << timestamp<<std::endl;
}

int main()
{
    //test_InitParam();
    //test_InitStruct(100,200);
    test_chrono();
    return 0;
}