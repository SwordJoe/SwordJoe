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

//判断矩形是否相交
void test_rectIntersection();

//随机生成顶点
void test_randu();