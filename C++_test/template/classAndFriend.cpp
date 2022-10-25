#include "iostream"
using namespace std;
/*
 类模板与友元
全局函数类内实现：直接在类内声明友元即可
全局函数类外实现：需要提前让编译器知道全局函数的存在
*/
//全局函数的类内实现,
template <typename T1, typename T2>
class Person
{
    friend void printPersson(Person<T1, T2> p)
    {
        cout << "name : " << p.m_name << " age: " << p.m_age << endl;
    }

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

private:
    T1 m_name;
    T2 m_age;
};
void test01()
{
    Person<string, int> p("ou", 222);
    printPersson(p);
}

//全局函数的类外实现
//提前让编译器知道Persso01类的存在
template <typename T3, typename T4>
class Person01;

//类外实现, 有参数
template <typename T3, typename T4>
void printPerson01(Person01<T3, T4> p)
{
    cout << "name:" << p.m_name << " age:" << p.m_age << endl;
}
//类外实现，无参数
template <typename T3, typename T4>
void printPerson02(void)
{
    cout <<"void" << endl;
}

template <typename T3, typename T4>
class Person01
{
    //全局函数类外实现 
	//加空模板参数列表"<>",也可以使用<string,int>，编译器根据参数可以推断出类型，所以空的也可以
    //但是如02所示，如果参数列表是void的，编译器无法推断类型，则需要使用模板参数语法<T3,T4>来指明具体化，调用的时候如line77，也需要指明类型
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson01<>(Person01<T3, T4> p);
    friend void printPerson02<T3,T4>(void);

public:
    Person01(T3 name, T4 age)
    {
        this->m_age = age;
        this->m_name = name;
    }

private:
    T3 m_name;
    T4 m_age;
};
void test02()
{
    Person01<string, int> p("zhu", 444);
    printPerson01(p);//这里可以使用printPerson01<string,int>(p)调用
    printPerson02<string,int>();
}
/*
注：需要注意各个函数声明之间的顺序。在Person类模板中有友元的声明friend void printPerson<>(Person<T1, T2> p)，
因为类模板中友元的类外实现需要让编译器提前知道这个函数，所以需要将printPerson函数写在前面。
而printPerson函数中又涉及Person类，所以在printPerson函数前面需要提前声明Person类模板的存在。
总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别。
*/
int main()
{
    test01();
    test02();
    system("pause");
}