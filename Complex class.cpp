#include <iostream>
using namespace std;
class Complex {
 public:
  Complex() {
    Re = 0;
    Lm = 0;
  }
  Complex(float a, float b) : Re(a), Lm(b) {
    cout << "正在构建类的实例，其实部为" << Re << "，虚部为" << Lm << endl;
  }
  Complex(const Complex& temp) {
    Re = temp.Re;
    Lm = temp.Lm;
    cout << "正在调用复制构建函数，实部为" << Re << "，虚部为" << Lm << endl;
  }
  void zset(float a, float b) {
    Re = a;
    Lm = b;
  }
  Complex add(Complex& a, Complex& b) {
    Complex temp;
    temp.Re = a.Re + b.Re;
    temp.Lm = a.Lm + b.Lm;
    cout << "正在调用add函数" << endl;
    return temp;
  }
  void show() {
    cout << "正在调用show函数" << endl;
    cout << Re << "+" << Lm << "i" << endl;
  }

 private:
  float Re;  // 实部是：real part，缩写就是Re
  float Lm;  // 虚部是：imaginary part，缩写就是Im
};
int main() {
  float m, n;
  cin >> m >> n;
  Complex z1(m, n);
  Complex ztemp;
  cin >> m;
  ztemp.zset(m, 0);
  Complex z2 = ztemp;
  z1 = z1.add(z1, z2);
  z1.show();
  return 0;
}