#include <iostream>
using namespace std;
/*与普通的成员变量和成员函数相比，静态成员函数和静态成员变量是属于类的，而不是属于对象的，
也就是说，在类实例化为对象之前，静态成员变量和静态成员函数就已经分配了内存空间了
，而普通成员函数和成员变量只有在对象产生之后才会分配空间。
静态成员变量：
    所有对象共享，使用静态成员变量实现多个对象之间的数据共享不会破坏隐藏的原则，保证了安全性还可以节省内存。
    在编译阶段分配内存
    类内声明，类外初始化
静态成员函数：
    所有对象共享同一个函数
    静态成员函数只能访问静态成员变量
    静态成员函数的主要功能就是访问静态成员变量。当然，非静态成员函数也可以访问静态成员变量。*/
class Person
{
public:
    int m_a;            //非静态成员变量
    static int m_age;       //静态成员变量
     void func()      //静态成员函数
    {
//      m_a=200; 报错 静态成员函数无法访问非静态成员变量，无法区分到底是哪个对象的变量
        this->m_age=200;
        this->m_a=200;
        cout<<"static Person::m_age="<<m_age<<endl;
        cout<<" Person::m_a="<<m_a<<endl;
    }
};

void func1()
{
    //1.通过对象访问
    Person p;
    p.func();
    //2.通过类名访问
    // Person::func(); //所有对象共享同一个函数
}
int Person::m_age=0;  //类外声明
int main() {
    func1();
    system("pause");
    return 0;
}

