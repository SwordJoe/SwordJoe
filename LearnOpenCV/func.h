#pragma once
#include<iostream> 
#include<vector>
#include<string>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//分离通道
void test_split();

//查找轮廓、绘制轮廓
void test_findContours_drawContours();

//计算面积
void test_contourArea();

//判断顶点是否在多边形内
void test_pointPolygonTest();

bool isPointInPolygon(double posX, double posY, vector<Point>& polygon);


//判断矩形是否相交
void test_rectIntersection();

//随机生成顶点
void test_randu();

//计算规则多变形的中心(质心)
Point computeCenterPoint(const vector<Point>& points);

//将顶点按照逆时针方向排列
bool comparePointsClockWise(const Point& a, const Point& b, const Point& center);

//自己写的计算多边形面积，并与OpenCV的contourArea的计算结果相比较
double CalcPolygonArea(vector<Point>& Polygon);

//测试上面的函数
bool test_CalcPolygonArea();
