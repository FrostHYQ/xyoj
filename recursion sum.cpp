#include <iostream>
#include <string>
using namespace std;
int Sum(int start, int end) {
  static int sum = 0;
  sum += start;
  if (start == end) {
    int res = sum;
    sum = 0;
    return res;
  }
  // 题目上要求仅用一个递归分段函数
  // 而递归应该起末相等就退出返回res
  // 所以我直接写了当start和end相等时就return sum
  // 但是后续遇到多次调用静态变量清零的问题，这里才用引入辅助变量res解决
  if (start > end) {
    int res = sum;
    sum = 0;
    return 0;
  }
  // 如果不包括末位则在此+=
  return Sum(start + 1, end);  // 递归
}
int main() {
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {  // EOF大法
    // 处理每组测试数据
    cout << Sum(a, b) << endl;
  }
  system("pause");
  return 0;
}