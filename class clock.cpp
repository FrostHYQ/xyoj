#include <iostream>
using namespace std;
class Clock {
 public:
  Clock() {
    cout << "The instance of class Clock is created" << endl;
    hour = 0;
    minute = 0;
    second = 0;
  }
  ~Clock() { cout << "The instance of class Clock is destroied" << endl; }
  void settime(int newH, int newmin, int news);
  void showtime();

 private:
  int hour, minute, second;
};
void Clock::settime(int newH, int newmin, int news) {
  hour = newH;
  minute = newmin;
  second = news;
  cout << "The new time value " << hour << ":" << minute << ":" << second
       << " is setted" << endl;
}  // 内部函数，设置时间，将对应‘m’
inline void Clock::showtime() {
  cout << "Time is " << hour << ":" << minute << ":" << second << endl;
}

int main() {
  Clock myClock;
  char input;
  while (cin >> input) {
    if (input == 'm') {
      int newHour, newMinute, newSecond;
      cin >> newHour >> newMinute >> newSecond;
      myClock.settime(newHour, newMinute, newSecond);
    } else if (input == 's') {
      myClock.showtime();
    } else if (input == 'e') {
      // myClock.~Clock();
      break;
    }
  }
  //   system("pause");
  return 0;
  // system("pause");
  // 析构函数不用显式调用，这东西会在数据清除时自己出现
}
