#include <cmath>  //这是C++的数学库函数，而math.h是C语言的
#include <iostream>
using namespace std;
class Point {
 public:
  Point() { x = y = 0; }
  void pointset(double a, double b) {
    x = a;
    y = b;
  }
  void pointshow() {
    cout << "点的坐标为：（" << x << "，" << y << "）" << endl;
  }
  friend void PointDis(Point &p1, Point &p2);
  friend void Axiscal(Point &p1,
                      Point &p2);  // axis是坐标轴（MATLAB）cal是计算缩写

 private:
  int x, y;
};
void PointDis(Point &p1, Point &p2) {  // pointdistance
  cout << "移动后点的坐标为：（" << p2.x << "，" << p2.y << "）" << endl;
  // double distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) +
  //                        pow((p2.z - p1.z), 2));
  // cout << "移动的距离为：" << distance << endl;
}
void Axiscal(Point &p1, Point &p2) {  // 不用更改的值可以用const
  p2.x += p1.x;
  p2.y += p1.y;
  cout << "X轴和Y轴增量后点的坐标为：（" << p2.x << "，" << p2.y << "）"
       << endl;
}
// class A，A a，A b=a进程同步
// 前向引用后不能声明对象，但可以有指针
// 不能补充说明，不过解决的方法还包括头文件!
int main() {
  double a, b;
  Point fisrtpoint, movepoint, axiscalpoint;
  cin >> a >> b;
  fisrtpoint.pointset(a, b);
  fisrtpoint.pointshow();
  cin >> a >> b;
  movepoint.pointset(a, b);
  PointDis(fisrtpoint, movepoint);
  cin >> a >> b;
  axiscalpoint.pointset(a, b);
  Axiscal(movepoint, axiscalpoint);
  return 0;
}