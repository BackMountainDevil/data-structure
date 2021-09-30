/*
参考：
http://c.biancheng.net/view/1407.html
https://www.runoob.com/cprogramming/c-structures.html
*/

#include <iostream>
#include <string>
using namespace std;

struct Student  // 定义结构体，名称为 Student
{
  string name;  // 姓名
  int age;      // 年龄
  Student()     // 默认构造函数
  {
    name = "zhangsan";
    age = 18;
  }
  Student(string n, int a) : name(n), age(a) {}  // 带参数的构造函数
};

int main() {
  Student unknown, lisi;
  lisi.name = "Li Si";
  lisi.age = 25;
  cout << "Name: " << unknown.name << " Age: " << unknown.age << endl;
  cout << "Name: " << lisi.name << " Age: " << lisi.age << endl;

  Student hg = {"Hu Ge", 17};  // 声明结构体的同时使用列表初始化
  cout << "Name: " << hg.name << " Age: " << hg.age << endl;

  Student xy("xiaoyi", 19);  // 声明结构体的同时初始化
  cout << "Name: " << xy.name << " Age: " << xy.age << endl;

  return 0;
}
