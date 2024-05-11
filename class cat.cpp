/*#include <iostream>
using namespace std;
class Boat;
// 静态的数目，普通的体重，只用第一个
// 因为直接在类里面进行了静态数据的调用，所以就没声称静态函数，一会儿试试
class Cat {
 public:
  Cat();
  Cat(float x) : weight(x) {
    numOfCats++;
    cout << "Cat Object is constructing, the constructed Number is "
         << numOfCats << ", and the living Number is "
         << numOfCats - numOfCatsGo << endl;
  }
  ~Cat() {
    numOfCatsGo++;
    cout << "Cat Object is deconstructing, and the living Number is "
         << numOfCats - numOfCatsGo << endl;
  }
  friend float getTotalWeight(Cat& p1, Boat& p2);

 private:
  float weight;
  static int numOfCats;
  static int numOfCatsGo;
};
class Boat {
 public:
  Boat(float x) : weight(x) {}
  friend float getTotalWeight(Cat& p1, Boat& p2);

 private:
  float weight;
};

Cat::Cat() : weight(0) {
  numOfCats++;
  cout << "Cat Object is constructing, the constructed Number is " << numOfCats
       << ", and the living Number is " << numOfCats - numOfCatsGo << endl;
}
int Cat::numOfCats = 0;
int Cat::numOfCatsGo = 0;

float getTotalWeight(Cat& p1, Boat& p2) { return p1.weight + p2.weight; }

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Cat cat0;
  }
  float x;
  cin >> x;
  Cat cat1(x);
  cin >> x;
  Boat boat1(x);
  x = getTotalWeight(cat1, boat1);
  cout << x << endl;
  return 0;
}*/

/*
* or 用for循环的局部变量
* delete的用法
Cat * cat0 = new Cat();
delete cat0;*/
/*
#include <iostream>
using namespace std;
class Boat;
class Cat {
 public:
  Cat();
  Cat(float x) : weight(x) {
    numOfCats++;
    IsConstruted = true;
  }
  ~Cat() {
    numOfCatsGo++;
    IsConstruted = false;
  }
  friend float getTotalWeight(Cat& p1, Boat& p2);
  static void getNumOfCats();

 private:
  float weight;
  static int numOfCats;
  static int numOfCatsGo;
  static bool IsConstruted;
  static bool getIsConstruted();
};

class Boat {
 public:
  Boat(float x) : weight(x) {}
  friend float getTotalWeight(Cat& p1, Boat& p2);

 private:
  float weight;
};

Cat::Cat() : weight(0) {
  numOfCats++;
  IsConstruted = true;
}

int Cat::numOfCats = 0;
int Cat::numOfCatsGo = 0;
bool Cat::IsConstruted = true;

float getTotalWeight(Cat& p1, Boat& p2) { return p1.weight + p2.weight; }

void Cat::getNumOfCats() {
  if (getIsConstruted()) {
    cout << "Cat Object is constructing, the constructed Number is "
         << numOfCats << ", and the living Number is "
         << numOfCats - numOfCatsGo << endl;
  } else {
    cout << "Cat Object is deconstructing, and the living Number is "
         << numOfCats - numOfCatsGo << endl;
  }
}

bool Cat::getIsConstruted() { return IsConstruted; }

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i != 0) Cat::getNumOfCats();
    Cat cat0;
    Cat::getNumOfCats();
  }
  float x;
  cin >> x;
  Cat* p = new Cat(x);
  Cat::getNumOfCats();
  cin >> x;
  Boat boat1(x);
  x = getTotalWeight(*p, boat1);
  cout << x << endl;
  delete p;
  Cat::getNumOfCats();
  return 0;
}*/

#include <iostream>
using namespace std;

class Cat;
class Boat {
 private:
  double weight;
  Cat* C;

 public:
  Boat(double w) : weight(w) {}
  void getTotalWeight(Cat* C);
};

class Cat {
 public:
  Cat(double w) : weight(w) { cout << "Cat Object is constructing, "; }
  ~Cat() { cout << "Cat Object is deconstructing, "; }
  static int numOfCats;
  static int numOfCatsGo;
  static void getNumOfCats(bool IsConstruted) {
    if (IsConstruted != 0)
      cout << "the constructed Number is " << numOfCats
           << ", and the living Number is 1" << endl;
    if (IsConstruted == 0)
      cout << "and the living Number is " << 1 - numOfCatsGo << endl;
  }
  friend void Boat::getTotalWeight(Cat* C);
  double getWeight() { return weight; }

 private:
  double weight;
};
// int Cat::numOfCats = 0;
// int Cat::numOfCatsGo = 0;

void Boat::getTotalWeight(Cat* C) { cout << weight + C->getWeight() << endl; }
int main() {
  int N;
  double w0, w1;
  Cat C(0);
  cin >> N;
  for (int i = 1; i <= N + 1; i++) {
    Cat::numOfCats = i;
    Cat::numOfCatsGo = 1;
    C.getNumOfCats(1);
    C.getNumOfCats(0);
  }
  cin >> w0;
  Cat cat(w0);
  cin >> w1;
  Boat B(w1);
  B.getTotalWeight(&cat);
  return 0;
}
