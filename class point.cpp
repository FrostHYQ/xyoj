#include <cmath>  //这是C++的数学库函数，而math.h是C语言的
#include <iostream>
using namespace std;
class Point {
 public:
  Point() { x = y = z = 0; }
  void pointset(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
  }
  void pointshow() {
    cout << "点的坐标为：（" << x << "，" << y << "，" << z << "）" << endl;
  }
  friend void PointDis(Point &p1, Point &p2);
  friend void Axiscal(Point &p1,
                      Point &p2);  // axis是坐标轴（MATLAB）cal是计算缩写

 private:
  double x, y, z;
};
void PointDis(Point &p1, Point &p2) {  // pointdistance
  cout << "移动后点的坐标为：（" << p2.x << "，" << p2.y << "，" << p2.z << "）"
       << endl;
  double distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) +
                         pow((p2.z - p1.z), 2));
  cout << "移动的距离为：" << distance << endl;
}
void Axiscal(Point &p1, Point &p2) {
  p2.x += p1.x;
  p2.y += p1.y;
  p2.z += p1.z;
  cout << "X轴、Y轴和Z轴增量后点的坐标为：（" << p2.x << "，" << p2.y << "，"
       << p2.z << "）" << endl;
}
int main() {
  double a, b, c;
  Point fisrtpoint, movepoint, axiscalpoint;
  cin >> a >> b >> c;
  fisrtpoint.pointset(a, b, c);
  fisrtpoint.pointshow();
  cin >> a >> b >> c;
  movepoint.pointset(a, b, c);
  PointDis(fisrtpoint, movepoint);
  cin >> a >> b >> c;
  axiscalpoint.pointset(a, b, c);
  Axiscal(fisrtpoint, axiscalpoint);
  system("pause");
  return 0;
}