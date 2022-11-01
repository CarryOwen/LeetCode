#include "iostream"
#include "MyArray.hpp"
#include "string"
/*
    1.可以对内置数据类型以及自定义数据类型的数据进行存储
    2.将数组中的数据存储到堆区
    3.构造函数中可以传入数组的容量
    4.提供对应的拷贝构造函数以及operator=防止浅拷贝的问题
    5.提供尾插法和尾删法对数组中的数据进行增加和删除
    6.可以通过下标的方式访问数组中的元素
    7.可以获取数组中当前元素个数和数组的容量
*/
using namespace std;
void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        //下标访问
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
    cout << "-----------test01 begin------------------" << endl;
    MyArray<int> arr1(5);    //调用普通构造
    MyArray<int> arr2(arr1); //调用拷贝构造
    MyArray<int> arr3(100);
    arr3 = arr1; //调用重载运算符“=”，即赋值函数
    MyArray<int> arr4(5);
    for (int i = 0; i < 5; i++)
    {
        arr4.push_back(i); //尾插法
    }
    cout << "arr4 = " << endl;
    printIntArray(arr4);
    cout << "arr4 capacity:" << arr4.get_capacity() << endl;
    cout << "arr4 size:" << arr4.get_size() << endl;
    MyArray<int> arr5(arr4);
    cout << "arr5 = " << endl;
    printIntArray(arr5);
    arr5.pop_back(); //尾删法
    cout << "delete arr5 : " << endl;
    printIntArray(arr5);
    cout << "------------test01 end-----------------" << endl;
}
//测试自定义类型
class Person
{
public:
    Person()
    {
    }
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string getName()
    {
        return this->m_name;
    }
    int getAge()
    {
        return this->m_age;
    }

private:
    string m_name;
    int m_age;
};
void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        cout << "Name:" << arr[i].getName() << endl;
        cout << "Age:" << arr[i].getAge() << endl;
    }
}
void test02()
{
    cout << "------------test02 begin-----------------" << endl;
    MyArray<Person> arr(10);
    Person p1("Tom", 11);
    Person p2("Bob", 12);
    Person p3("Ka", 13);

    //数据插入到数组中
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);

    printPersonArray(arr);
    cout << "arr capacity:" << arr.get_capacity() << endl;
    cout << "arr size:" << arr.get_size() << endl;
    cout << "------------test02 end-----------------" << endl;
}
int main()
{
    test01();
    test02();
    // int *p = new int[5]{1, 2, 3, 4, 5};//03版本以后的初始化方式
    system("pause");
}