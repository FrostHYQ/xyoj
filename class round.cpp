/*
#include <iostream>
using namespace std;

class A {
 public:
  void foo() { printf("1\n"); }
  virtual void fun() { printf("2\n"); }
};
class B : public A {
 public:
  void foo()  // 隐藏：派生类的函数屏蔽了与其同名的基类函数
  {
    printf("3\n");
  }
  void fun()  // 多态、覆盖
  {
    printf("4\n");
  }
};
int main(void) {
  A a;
  B b;
  A *p = &a;
  p->foo();  // 输出1
  p->fun();  //
  p = &b;
  B *p1 = &b;
  p1->foo();  // 输出3,取决于指针类型
  p->foo();   // 取决于指针类型，输出1
  p->fun();   // 取决于对象类型，输出4，体现了多态
  return 0;
}*/

#include <cmath>
#include <iomanip>
#include <iostream>
const float PI = 3.1415926;
using namespace std;

class Point {
 public:
  Point() { X = Y = 0; }
  Point(int a, int b) {
    X = a;
    Y = b;
  }
  virtual void pointshow() {
    cout << "点的坐标为：（" << X << "，" << Y << "）" << endl;
  }
  virtual void Move(int a, int b) {  // pointdistance
    X = a;
    Y = b;
    cout << "移动后点的坐标为：（" << X << "，" << Y << "）" << endl;
  }

 protected:
  int X, Y;
};

class Circle : protected Point {
 protected:
  double radius;

 public:
  Circle(double r, int x, int y) : Point(x, y) { radius = r; }

  void setRadius(double r) { radius = r; }

  void calculatePerimeter() {
    cout << "圆的周长为：" << fixed << setprecision(2) << 2 * PI * radius
         << endl;
  }

  void showCircleR() {
    cout << "圆的半径为：" << fixed << setprecision(2) << radius << endl;
  }
  void pointshow() {
    cout << "圆的初始圆心坐标为：（" << X << "，" << Y << "）" << endl;
  }

  void Move(int deltaX, int deltaY) {
    X = deltaX;
    Y = deltaY;
    cout << "圆移动后的圆心坐标为：（" << X << "，" << Y << "）" << endl;
  }

  Circle operator+(const Circle &p) {
    Circle temp(0, 0, 0);
    temp.X = (this->X + p.X) / 2;
    temp.Y = (this->Y + p.Y) / 2;
    temp.radius = (this->radius + p.radius);
    return temp;
  }
};

int main() {
  int x, y;
  float r;
  char c;
  cin >> x >> y;
  cin >> r;
  Circle circle1(r, x, y);
  circle1.pointshow();
  circle1.showCircleR();
  circle1.calculatePerimeter();
  while ((c = getchar()) != '\n');
  cin >> x >> y;
  circle1.Move(x, y);
  while ((c = getchar()) != '\n');
  cin >> x >> y >> r;
  Circle circle2(r, x, y);
  circle2.pointshow();
  circle2.showCircleR();
  Circle circle3 = circle1 + circle2;
  circle3.pointshow();
  circle3.showCircleR();
  return 0;
}
