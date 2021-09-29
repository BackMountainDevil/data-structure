/*
指针：变量的内存地址。
每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，
它表示变量在内存中的一个地址。

* ：返回位于操作数所指定地址的变量的值
& ：返回变量的内存地址的值
声明指针变量  type *name
给指针变量赋值某变量的地址 name=&varname
取出地址对于的内容  cout<<*name

参考：https://www.runoob.com/cplusplus/cpp-pointers.html
输出参考：（地址在不同机器不同时间运行结果极大概率不同，但是核心是变量地址和指针内容是一样的）
var1 变量的地址： 0x7ffd8f6c2c44
var2 变量的地址： 0x7ffd8f6c2c48
var3 变量的地址： 0x7ffd8f6c2c65
指针变量 ip 中存储的地址: 0x7ffd8f6c2c44 指针中地址的值: 110
指针变量 dp 中存储的地址: 0x7ffd8f6c2c48 指针中地址的值: 3.1415
*/

#include <iostream>

using namespace std;

int main() {
  int var1 = 110;
  double var2 = 3.1415;
  char var3[3] = {'3', '2', '1'};
  cout << "var1 变量的地址： ";
  cout << &var1 << endl;
  cout << "var2 变量的地址： ";
  cout << &var2 << endl;
  cout << "var3 变量的地址： ";
  cout << &var3 << endl;

  int *ip;     // 声明一个整型的指针变量
  ip = &var1;  // 在指针变量中存储 var1 的地址
  cout << "指针变量 ip 中存储的地址: " << ip << " 指针中地址的值: " << *ip
       << endl;
  double *dp = &var2;
  cout << "指针变量 dp 中存储的地址: " << dp << " 指针中地址的值: " << *dp
       << endl;

  return 0;
}
