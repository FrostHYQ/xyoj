#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// 定义营养级常量
const int GRASS = 1;
const int SMALL_CARNIVORE = 2;
const int MEDIUM_CARNIVORE = 3;
const int LARGE_CARNIVORE = 4;
const int HUMAN = 5;
struct AnimalType {
  int count;
  string names;
  // vector<string> name;
};
// 动物基类
class Animal {
 protected:
  double height;
  double weight;
  double speed;

 public:
  Animal(string n, double h, double w, double s, int tl)
      : name(n), height(h), weight(w), speed(s), trophicLevel(tl) {}
  virtual bool canPredate(Animal& other) = 0;  // 纯虚函数，用于捕食判断
  virtual ~Animal() {}

  double getHeight() const { return height; }
  double getWeight() const { return weight; }
  double getSpeed() const { return speed; }
  string getName() const { return name; }
  int trophicLevel;
  string name;
};

// 食草动物类
class Herbivore : public Animal {
 public:
  Herbivore(string name, double h, double w, double s)
      : Animal(name, h, w, s, GRASS) {}
  bool canPredate(Animal& other) override {
    return false;  // 食草动物不能捕食
  }
};

// 食肉动物基类
class Carnivore : public Animal {
 public:
  Carnivore(string name, double h, double w, double s, int tl)
      : Animal(name, h, w, s, tl) {}
  bool canPredate(Animal& other) override {
    if (other.trophicLevel == GRASS && this->speed > other.getSpeed()) {
      return true;  // 食肉动物可以捕食食草动物
    } else if (this->trophicLevel > other.trophicLevel + 1 &&
               this->speed > other.getSpeed()) {
      return true;
    } else if (this->trophicLevel > other.trophicLevel &&
               this->height > other.getHeight() &&
               this->weight > other.getWeight() &&
               this->speed > other.getSpeed()) {
      return true;
    } else
      return false;  // 食肉动物不能捕食其他食肉动物
  }
};

// 大型食肉动物类
class LargeCarnivore : public Carnivore {
 public:
  LargeCarnivore(string name, double h, double w, double s)
      : Carnivore(name, h, w, s, LARGE_CARNIVORE) {}
};

// 中型食肉动物类
class MediumCarnivore : public Carnivore {
 public:
  MediumCarnivore(string name, double h, double w, double s)
      : Carnivore(name, h, w, s, MEDIUM_CARNIVORE) {}
};

// 小型食肉动物类
class SmallCarnivore : public Carnivore {
 public:
  SmallCarnivore(string name, double h, double w, double s)
      : Carnivore(name, h, w, s, SMALL_CARNIVORE) {}
};

// 人类类
class Human : public Animal {
 public:
  Human(string name, double h, double w, double s)
      : Animal(name, h, w, s, HUMAN) {}
  bool canPredate(Animal& other) override {
    return false;  // 人类不捕食
  }
};

// 主程序
int main() {
  int numAnimals;
  cin >> numAnimals;

  vector<Animal*> animals;

  for (int i = 0; i < numAnimals; ++i) {
    string type;
    string name;
    double height, weight, speed;
    cin >> type >> name >> height >> weight >> speed;

    if (type == "R") {
      animals.push_back(new Human(name, height, weight, speed));
    } else if (type == "H") {
      animals.push_back(new Herbivore(name, height, weight, speed));
    } else if (type == "SC") {
      animals.push_back(new SmallCarnivore(name, height, weight, speed));
    } else if (type == "MC") {
      animals.push_back(new MediumCarnivore(name, height, weight, speed));
    } else if (type == "LC") {
      animals.push_back(new LargeCarnivore(name, height, weight, speed));
    }
  }
  vector<AnimalType> res(5);  // 初始化为5种营养级，不包括人类
  for (auto& t : res) {
    t.count = 0;
    t.names = "";
  }
  bool hasHuman = false;
  for (Animal* animal : animals) {
    if (animal->trophicLevel == HUMAN) {
      hasHuman = true;
      break;
    }
  }
  if (!hasHuman) {
    for (size_t i = 0; i < animals.size() - 1; i++) {
      if (animals[i]->canPredate(*animals[i + 1])) {
        animals.erase(animals.begin() + i + 1);
      } else if (animals[i + 1]->canPredate(*animals[i])) {
        animals.erase(animals.begin() + i);
      }
    }
  }

  for (Animal* animal : animals) {
    int index = animal->trophicLevel - 1;  // 将营养级转换为数组索引
    res[index].count++;
    if (!res[index].names.empty()) {
      res[index].names += ", ";  // 添加分隔符
    }
    res[index].names += animal->name;
  }

  map<int, string> type_names = {{1, "Herbivore"},
                                 {2, "Small Carnivore"},
                                 {3, "Medium Carnivore"},
                                 {4, "Large Carnivore"},
                                 {5, "Human"}};

  // 输出每种动物类型及其数量和名字
  cout << "Remaining animals:" << endl;
  for (int i = 0; i < res.size(); ++i) {
    if (res[i].count > 0) {
      cout << type_names[i + 1] << " (" << res[i].count << "): " << res[i].names
           << endl;
    }
  }
  // 清理动态分配的内存
  for (Animal* animal : animals) {
    delete animal;
  }
  return 0;
}