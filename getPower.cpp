#include <math.h>
#include <iostream>
using namespace std;
// 听说过递归，毕竟上学期有汉诺塔，又有字符的全排列
// DFS算的上微微了解
// 重载函数没听说过
// 刚刚去菜鸟教程看了看，大概了解，我试试
int powbranch(int n, int m) {
  if (m == 0)
    return 1;  // 终点
  else if (m % 2 != 0) {
    int temp = powbranch(n, m / 2);
    return temp * temp * n;
  } else {
    int temp = powbranch(n, m / 2);
    return temp * temp;
  }
}  // 果然好久不写，一个寒假手生了
// 既然要递归，除了重载的相关问题，（重载决策）
// 采用了分治的快速幂+迭代
// 如果直接调用math的pow可能不合题意
// 所以手写了这个，但因为不熟练还是搜了搜，不算盲写
int power(int n, int m) {
  if (n == 1 || m == 0)
    return 1;
  else if (m < 0)
    return 1 / powbranch(n, abs(m));
  else
    return powbranch(n, m);
}
double powbranch(double n, int m) {
  if (m == 0) {
    return 1;  //
  } else if (m % 2 != 0) {
    double temp = powbranch(n, m / 2);
    return temp * temp * n;
  } else {
    double temp = powbranch(n, m / 2);
    return temp * temp;
  }
}
double power(double n, int m) {
  if (n == 1 || m == 0)
    return 1;
  else if (m < 0)
    return 1 / powbranch(n, abs(m));
  else
    return powbranch(n, m);
}
int main() {
  int a = 0, m = 0;
  double b = 0;
  double myPow(double x, int n);
//  cin >> a >> b >> m;
//  cout << pow(b, m);
   while (scanf("%d%lf%d", &a, &b, &m) != EOF) {
     cout << power(a, m) << endl;
     cout << power(b, m) << endl;
   }
  // 检测了一下，是while里的问题。
//  system("pause");
     return 0;
}













/*
double myPowBranch(double n, long long k) {
  if (k == 1) {
    return n;
  } else if (k % 2 != 0) {
    double temp = myPowBranch(n, k / 2);
    return temp * temp * n;
  } else {
    double temp = myPowBranch(n, k / 2);
    return temp * temp;
  }
}
double myPow(double n, double k) {
  if (n == 1 || k == 0) {
    return 1;
  } else if (k < 0) {
    return 1 / myPowBranch(n, (long long)abs(k));
  } else {
    return myPowBranch(n, (long long)k);
  }
}*/
//double myPow(double x, int n);
//double quickMul(double x, long long N) {
//  if (N == 0) {
//    return 1.0;
//  }
//  double y = quickMul(x, N / 2);
//  return N % 2 == 0 ? y * y : y * y * x;
//}
//
//double myPow(double x, int n) {
//  long long N = n;
//  return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
//}
