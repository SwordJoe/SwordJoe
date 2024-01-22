#include"head.h"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
using namespace std;

const char* LENA = "E:\\PicForTest\\lena.jpg";
const char* MAPLELEAF = "E:\\PicForTest\\mapleLeaf.jpg";

//计算多边形的中心点（质心）
Point computeCenterPoint(const vector<Point>& points) {
	Point centerPoint(0, 0);
	for (auto p : points) {
		centerPoint.x += p.x;
		centerPoint.y += p.y;
	}

	centerPoint.x /= points.size();
	centerPoint.y /= points.size();

	return centerPoint;
}
//以质心为参考点，逆时针排列顶点
bool comparePointsClockWise(const Point& a, const Point& b, const Point& center) {
	double angleA = atan2(a.y - center.y, a.x - center.x);
	double angleB = atan2(b.y - center.y, b.x - center.x);
	return angleA < angleB;
}

bool isPointInPolygon(double posX, double posY, vector<Point>& polygon) {
	int i = 0;
	int j = polygon.size() - 1;
	bool flag = false;

	while (i < polygon.size()) {
		if ((polygon[i].y > posY) != (polygon[j].y > posY) &&
			(posX < (polygon[j].x - polygon[i].x) * (posY - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)
			)
		{
			flag = !flag;
		}
		j = i++;
	}

	return flag;
}
void test_split() {
	Mat img = imread(LENA);
	//cvtColor(img, img, COLOR_BGR2RGB);
	cvtColor(img, img, COLOR_BGR2YUV_I420);
	vector<Mat> channels;

	split(img, channels);
	cout << channels[0].channels() << endl;
	cout << channels[0].elemSize() << endl;
	for (int i = 0; i < channels.size(); ++i) {
		imshow(to_string(i), channels[i]);
	}

	cv::imwrite("E:\\PicForTest\\lena_R.jpg", channels[0]);
	cv::imwrite("E:\\PicForTest\\lena_G.jpg", channels[1]);
	cv::imwrite("E:\\PicForTest\\lena_B.jpg", channels[2]);

	waitKey(5000);
}

void test_findContours_drawContours()
{
	//载入原始图，且必须以0为参数从而载入二值图
	Mat srcImg = imread(LENA, 0);
	imshow("原始图", srcImg);

	//目标图像设置为白底
	Mat contourImg(srcImg.rows, srcImg.cols, CV_8UC3, Scalar::all(255));

	srcImg = srcImg > 119;
	imshow("取阈值后的图", srcImg);

	//定义轮廓和层次结构
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//查找轮廓
	findContours(srcImg, contours, hierarchy, RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

	//遍历所有顶层轮廓，绘制
	int idx = 0;
	for (; idx >= 0; idx = hierarchy[idx][0]) {
		drawContours(contourImg, contours, idx, Scalar(0,0,255), 1, 8, hierarchy);	//1如果改成FILLED，就会把轮廓内部填充满
	}

	Point point(195,165);
	bool ret = pointPolygonTest(contours[1], point, false);
	cout << (ret ? "true" : "false") << endl;
	//double dist = pointPolygonTest(contours[1], point, true);
	//cout << "dist=" << dist << endl;

	imshow("轮廓图", contourImg);
	waitKey(0);
}

void test_contourArea() {
	vector<Point2f> contour;
	contour.push_back(Point2f(10,20));
	contour.push_back(Point2f(30,20)); 
	contour.push_back(Point2f(30,40));
	contour.push_back(Point2f(10,40));
	/*contour.push_back(Point2f(2, 20)); 10 20 30 20 10 40 30 40*/

	double area = contourArea(contour);
	cout << "area = " << area << endl;

}

void test_pointPolygonTest() {
	vector<Point> polygon;
	polygon.push_back(Point(10,20));
	polygon.push_back(Point(30,20));
	polygon.push_back(Point(30,40));
	polygon.push_back(Point(10,40));

	// 创建一个黑色图像作为背景
	Mat image = Mat::zeros(500, 500, CV_8UC3);
	vector<vector<Point>> contours;
	contours.push_back(polygon);
	drawContours(image, contours, 0, Scalar(255, 255, 255), FILLED);
	
	Point point(26, 25);
	int ret = pointPolygonTest(polygon, point,false);
	cout << ret << endl;

	// 显示结果图像
	imshow("Random Polygon", image);
	waitKey(0);
	destroyAllWindows();
}

void test_rectIntersection() {
	Rect rectA(1, 5, 5, 5);
	Rect rectB(100, 100, 5, 5);

	/*Rect intersectionRect = rectA & rectB;
	cout << intersectionRect.x << endl;
	cout << intersectionRect.y << endl;
	cout << intersectionRect.width << endl;
	cout << intersectionRect.height << endl;
	cout << intersectionRect.area() << endl;*/

	Rect unionRect = rectA | rectB;
	cout << unionRect.x << endl;
	cout << unionRect.y << endl;
	cout << unionRect.width << endl;
	cout << unionRect.height << endl;
	cout << unionRect.area() << endl;
}

void test_randu() {
	// 设置随机种子
	srand(static_cast<unsigned>(time(0)));
	// 创建一个黑色图像作为背景
	Mat image = Mat::zeros(500, 500, CV_8UC3);
	
	// 生成随机500*500内的随机顶点
	int VerticesNum = 6;
	vector<Point> points;
	for (int i = 0; i < VerticesNum; ++i) {
		points.emplace_back(rand() % 500, rand() % 500);
	}
	// 对顶点进行排序
	Point center(image.cols / 2, image.rows / 2);
	sort(points.begin(), points.end(), [center](const Point& a, const Point& b) {
		return comparePointsClockWise(a, b, center);
		});
	std::cout << "随机生成的顶点坐标:\n";
	for (auto p : points) { 
		std::cout << p.x << " " << p.y << std::endl;
	}
	std::cout << std::endl;

	// 将多边形绘制在图像上
	vector<vector<Point>> contours;
	contours.push_back(points);
	drawContours(image, contours, 0, Scalar(255, 255, 255), 1);


	// 设置图像中某个点的颜色值为红色 (0, 0, 255)
	Point point(rand() % 300, rand() % 300);
	std::cout << point.x << " " << point.y << std::endl;
	image.at<Vec3b>(point) = Vec3b(0, 0, 255);
	image.at<Vec3b>(points[0]) = Vec3b(0, 0, 255);

	bool ret = pointPolygonTest(points, point, false);
	std::cout << "OpenCV函数结果:\t" << ret << std::endl;

	bool ret2 = isPointInPolygon(point.x, point.y, points);
	std::cout << "自定义函数结果:\t" << ret2 << std::endl;
	// 显示结果图像 
	imshow("Random Polygon", image);
	waitKey(0);
	destroyAllWindows();
}

double CalcPolygonArea(vector<Point>& Polygon) {
	double area = 0;
	int n = Polygon.size();
	if (Polygon.size() < 0) {
		return 0.0;
	}

	Point prev;
	prev.x = Polygon[n - 1].x;
	prev.y = Polygon[n - 1].y;
	
	//算法原理：https://zhuanlan.zhihu.com/p/110025234
	for (int i = 0; i < n; ++i) {
		area += (double)prev.x * Polygon[i].y - (double)prev.y * Polygon[i].x;
		prev = Polygon[i];
	}

	area *= 0.5;

	return area;
}

bool test_CalcPolygonArea() {
	vector<Point> points;
	srand(static_cast<unsigned>(time(0)));

	for (int i = 0; i < 10; ++i) {
		points.emplace_back(rand() % 500, rand() % 500);
	}

	/*for (auto p : points) {
		cout << p.x << " " << p.y << endl;
	}
	cout << "\n";*/

	Point centerPoint = computeCenterPoint(points);
	sort(points.begin(), points.end(), [centerPoint](Point p1, Point p2) {
		return comparePointsClockWise(p1, p2, centerPoint);
		});
	/*for (auto p : points) {
		cout << p.x << " " << p.y << "\t" << atan2(p.y - centerPoint.y, p.x - centerPoint.x) << endl;
	}*/

	//cout << endl;

	double area1 = CalcPolygonArea(points);
	double area2 = contourArea(points);
	
	return area1 == area2;
}