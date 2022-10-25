/*
当类模板碰到继承时，需要注意以下几点：
当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
如果不指定，编译器无法给子类分配内存
如果想灵活指定出父类中T的类型，子类也需为类模板
*/
//类模板与继承
template<typename T>
class base
{
    T m;
};
// class son1:public base //错误，必须要知道父类中的T类型，才能继承给子类
class son1:public base<int>
{
};

//如果想要灵活指定父类中T的类型，子类也需要变成类模板
template<class T1,class T2>
class son2: public base<T2>
{
    son2()
    {

    }
    T1 obj;
};