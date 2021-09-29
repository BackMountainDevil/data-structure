/*
参考：
http://c.biancheng.net/view/1407.html
https://www.runoob.com/cprogramming/c-structures.html
*/

#include <iomanip>
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
};

int main() {
  Student unknown, lisi;
  lisi.name = "Li Si";
  lisi.age = 25;
  cout << "Name: " << unknown.name << " Age: " << unknown.age << endl;
  cout << "Name: " << lisi.name << " Age: " << lisi.age << endl;

  return 0;
}
