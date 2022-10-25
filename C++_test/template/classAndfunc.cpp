#include "iostream"
#include "algorithm"
#include "string"
/*
学习目标：类模板实例化出的对象，向函数传参的方式
一共有三种传入方式：
指定传入的类型：直接显示对象的数据类型
参数模板化：将对象中的参数变为模板进行传递
整个类模板化：将这个对象类型模板化进行传递
*/
using namespace std;
template <typename T1, typename T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPersion()
    {
        cout << "name: " << m_name << " age: " << m_age << endl;
    }
    T1 m_name;
    T2 m_age;
};
// 1.指定传入类型
void printPersion1(Person<string, int> *p)
{
    p->showPersion();
    delete p;
}
void test01()
{
    Person<string, int> *p = new Person<string, int>("zhu", 123);
    // Person<string, int> p("zhu", 123);
    printPersion1(p);
}
// 2.参数模板化
template <class T1, class T2>
void printPersion2(Person<T1, T2> &p)
{
    p.showPersion();
    cout << "T1 tpye:" << typeid(T1).name() << endl;
    cout << "T2 tpye:" << typeid(T2).name() << endl;
}
void test02()
{
    Person<string, int> p("ou", 123);
    printPersion2(p);
}
// 3.整个类模板化
template <class T>
void printPersion3(T &p)
{
    p.showPersion();
    cout << "T tpye:" << typeid(T).name() << endl;
}
void test03()
{
    Person<string,int> p("xzz", 123);
    printPersion3(p);
}
int main()
{
    test01();
    test02();
    test03();
    system("pause");
}