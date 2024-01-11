// bool isPointInPolygon(const TETPoint& point, const std::vector<cv::Point2f>& polygon);
// bool isPointInPolygon(int x, int y, const std::vector<cv::Point2f>& polygon);
#ifndef _FUNC_H_
#define _FUNC_H_
#include<vector>
struct KeDaPoint{
    int x{0};
    int y{0};
};

bool isPointInPolygon(double posX, double posY, std::vector<KeDaPoint> &polygon);


#endif
