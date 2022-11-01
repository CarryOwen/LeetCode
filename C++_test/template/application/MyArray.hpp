#include "iostream"
using namespace std;
// hpp文件是将类模板进行分文件编写，声明和实现写在一个文件，
//为了防止类模板中的成员函数一开始不创建，运行时才创建的特性，导致无法解析的问题
template <typename T>
class MyArray
{
public:
    MyArray(int capacity);                  //普通构造
    MyArray(const MyArray &arr);            //拷贝构造
    MyArray &operator=(const MyArray &arr); //赋值函数
    ~MyArray();
    void push_back(const T &val);   //尾插法
    void pop_back(void);            //尾删法
    T &operator[](int index) const; //下标方位，防止成员函数修改对象的值
    int get_capacity(void);         //获取容量
    int get_size(void);             //获取数组大小

private:
    T *pAddress;    //指针指向堆区开辟的真实数组
    int m_capacity; //数组容量
    int m_size;     //数组大小
};
//普通构造
template <typename T>
MyArray<T>::MyArray(int capacity)
{
    cout << "MyArray construct normal!" << endl;
    this->m_capacity = capacity;
    this->m_size = 0;
    this->pAddress = new T[this->m_capacity](); //创建T类型的数组，但是数组值没有初始化，可以加上括号把值全部初始化为0---》new T[this->m_capacity]()
    //03版c++以后还可以这样在堆上初始化数组 int *p =new int[5]{1,2,3,4,5}

}
//拷贝构造
template <typename T>
MyArray<T>::MyArray(const MyArray &arr)
{
    cout << "MyArray Copy structure!" << endl;
    // MyArray tmp(arr); //拷贝构造，临时使用
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;
    //深拷贝
    this->pAddress = new T[this->m_capacity];
    for (int i = 0; i < this->m_size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }
}
//赋值函数
template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray &arr)
{
    cout << "MyArray assignment!" << endl;
    //先判断原来的堆区是不是有数据，有的话先清除
    if (this->pAddress != NULL)
    {
        delete[] this->pAddress;
        this->pAddress = NULL;
        this->m_capacity = 0;
        this->m_size = 0;
    }
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;

    //深拷贝
    this->pAddress = new T[this->m_capacity];
    for (int i = 0; i < this->m_size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }
    return *this;
}
//析构函数
template <typename T>
MyArray<T>::~MyArray()
{
    if (this->pAddress != NULL)
    {
        cout << "destroy!" << endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
        this->m_capacity = 0;
        this->m_size = 0;
    }
}
//尾插法
template <typename T>
void MyArray<T>::push_back(const T &val)
{
    if (this->m_size == this->m_capacity)
        return;                         //超过容量
    this->pAddress[this->m_size] = val; //尾部插入
    this->m_size++;
}
//尾删法
template <typename T>
void MyArray<T>::pop_back(void)
{
    //让用户访问不到最后一个元素
    if (this->m_size == 0)
        return;
    this->m_size--;
}
//下标访问
template <typename T>
T& MyArray<T>::operator[](int index) const
{
    return this->pAddress[index]; 
}
//返回数组容量
template <typename T>
int MyArray<T>::get_capacity()
{
    return this->m_capacity;
}
//返回数组大小
template<typename T>
int MyArray<T>::get_size()
{
    return this->m_size;
}