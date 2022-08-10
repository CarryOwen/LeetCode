
#include <iostream>
#include<string.h>
#include "vector"
/*
对于任意一个类Class A，如果程序员不显示的声明和定义上述函数，C
++编译器将会自动的为A产生4个public inline 的默认函数，如下
*/
class tg_string
{
public:
    tg_string(const char *str = nullptr);// 普通构造函数
    tg_string(const tg_string &other);// 拷贝构造函数
    tg_string & operator = (const tg_string &other);// 赋值函数
 
    ~tg_string(void);// 析构函数
private:
    char *m_data;// 成员含有指针，若使用类的等号赋值的时候需要显示的提供赋值函数（上面的第三个）和拷贝构造
};
 
// String的析构函数
tg_string::~tg_string(void)
{
    std::cout<<"deconstruct:"<<m_data<<std::endl;
    delete[] m_data;
}
 
//普通构造函数
tg_string::tg_string(const char *str)
{
    if (str == nullptr)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        size_t length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
    std::cout<<"construct:"<<m_data<<std::endl;
}
 
//拷贝构造函数 因为成员中含有指针，所以必须对拷贝函数进行重写，实现深拷贝。不重写的话，默认拷贝构造属于浅拷贝，不会为指针分配内存，释放的时候就会对同一块内存释放两次，造成泄漏
tg_string::tg_string(const tg_string &other)
{
    size_t length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    std::cout<<"copy construct:"<<m_data<<std::endl;
}
 
//赋值函数
//返回值tg_string & 自身类型的引用，return *this可以使用连等赋值,tg_string  t2 t3; t2=t3=t1
//形参const tg_string &other 为类本身的引用，使得调用赋值函数时无需再次重复调用拷贝构造函数为形参申请临时空间，类型为const可以保护已有对象在进行赋值时自身的数据安全

tg_string & tg_string::operator = (const tg_string &other)
{
    std::cout<<"copy assignment"<<std::endl;
    if (this == &other)//这里是为了防止自身给自身赋值时的重复调用
    {
        return *this;
    }
 
    tg_string tmp(other);
    char* ptr= this->m_data;
    this->m_data = tmp.m_data;
    tmp.m_data = ptr;
 
    return *this;
}
/* emplace操作是C++11新特性，新引入的的三个成员emplace_front、emplace 和 emplace_back。
 这些操作构造而不是拷贝元素到容器中，这些操作分别对应push_front、insert 和push_back，允许我们将元素放在容器头部、一个指定的位置和容器尾部。
两者的区别 
    当调用insert时，是将对象传递给insert，对象被拷贝到容器中，
    而当我们使用emplace时，是将参数传递给构造函，emplace使用这些参数在容器管理的内存空间中直接构造元素。
    总结，emplace相对于push，insert对于向队列中插入类对象的时候，性能更好，因为少了一次拷贝构造的调用
*/
int main()
{
    {
        std::cout<<"++++++++++++++++++++++++++++++++++"<<std::endl;
        std::vector<tg_string> vStr;
        // 预先分配，否则整个vector在容量不够的情况下重新分配内存
        vStr.reserve(100);
        vStr.push_back(tg_string("first"));
    }
    {
        std::vector<tg_string> vStr;
        // 预先分配，否则整个vector在容量不够的情况下重新分配内存
        vStr.reserve(100);
        std::cout<<"++++++++++++++++++++++++++++++++++"<<std::endl;
        vStr.emplace_back("second");
     }
 
    return 0;
}