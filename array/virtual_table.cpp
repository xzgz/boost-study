#include <iostream>


using namespace std;

class Base {
 public:
  virtual void f() { cout << "Base::f" << endl; }
  virtual void g() { cout << "Base::g" << endl; }
  virtual void h() { cout << "Base::h" << endl; }
};


typedef void(*Fun)();

int main()
{
  Base b;

  Fun pFun1 = (Fun)*((long*)*(long*)(&b) + 0);
  Fun pFun2 = (Fun)*((long*)*(long*)(&b) + 1);
  Fun pFun3 = (Fun)*((long*)*(long*)(&b) + 2);
  cout << "&b bytes: " << sizeof(&b) << endl;
  cout << "long bytes: " << sizeof(long) << endl;

  cout << "virtual table address: " << (long *)&b << endl;
  cout << "f() address in virtual table: " << (long*)*(long*)(&b) + 0 << endl;
  cout << "g() address in virtual table: " << (long*)*(long*)(&b) + 1 << endl;
  cout << "h() address in virtual table: " << (long*)*(long*)(&b) + 2 << endl;

  pFun1();
  pFun2();
  pFun3();
}