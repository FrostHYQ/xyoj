#include <iostream>
using namespace std;
float legendre(int n, float x) {
  float p;
  if (n == 0) p = 1;
  if (n == 1) p = x;
  if (n > 1)
    p = ((2 * n - 1) * x * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) /
        n;
  return p;  // 不需要终止，因为只要递归结束p值得出自己就会出来
}
int main() {
  int a;
  float b;
  while (scanf("%d%f", &a, &b) != EOF) {  // EOF大法
    // 处理每组测试数据
    cout << legendre(a, b) << endl;
  }
  return 0;
  //   system("pause");
}