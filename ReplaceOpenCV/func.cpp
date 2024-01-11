#include"func.h"
// bool isPointInPolygon(int n, double pos_x, double pos_y, double vert[][2])
// {
//     int i, j, c = 0;
	
// 	for (i = 0, j = n - 1; i < n; j = i++)
// 	{
// 	      if (
//                 ((vert[i][1] > pos_y) != (vert[j][1] > pos_y)) &&
// 		        (pos_x < (vert[j][0] - vert[i][0]) * (pos_y - vert[i][1]) / (vert[j][1] - vert[i][1]) + vert[i][0])
//              )
// 	      {
// 		  c = !c;
// 	      }
// 	}	
// 	return c;
// }
//https://download.csdn.net/download/weixin_38617604/12809626?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-download-2%7Edefault%7ECTRLIST%7EPaid-1-12809626-blog-99694448.235%5Ev40%5Epc_relevant_default_base&depth_1-utm_source=distribute.pc_relevant_t0.none-task-download-2%7Edefault%7ECTRLIST%7EPaid-1-12809626-blog-99694448.235%5Ev40%5Epc_relevant_default_base&utm_relevant_index=1
bool isPointInPolygon(double posX, double posY, std::vector<KeDaPoint> &polygon){
    int i = 0;
    int j = polygon.size() - 1;
    bool flag = false;

    while( i < polygon.size()){
        if( (polygon[i].y > posY) != (polygon[j].y > posY ) && 
            (posX < (polygon[j].x - polygon[i].x) * (posY - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)
        )
        {
            flag = !flag;
        }
        j = i++;
    }

    return flag;
}