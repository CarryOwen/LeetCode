#include "iostream"
using namespace std;
//构造函数主要包括：默认构造函数、普通构造函数、拷贝构造函数三种。
//另外，
class CopyTest
{
public:
    CopyTest(){}
    CopyTest(CopyTest& cp) { cout << "kaobeigouzao" << endl; }
    CopyTest& operator=(const CopyTest& cp) { cout << "fuzhigouzao" << endl; }
};
CopyTest show(CopyTest mmm)
{
    return mmm;
}
CopyTest& show1(CopyTest mmm)
{
    return mmm;
}

int main()
{
    CopyTest tttt;
	CopyTest ttt1 = tttt;//会调用拷贝构造函数，类似的如CopyTest ttt1(tttt) 也会调用拷贝构造，
    //并且这种拷贝属于浅拷贝，如果成员中存在指针变量的话，两个初始化的类ttt1和tttt中的指针指向的同一块内存，两个对象销毁的时候会调用两次析构，对同一块内存释放两次，造成内存泄漏，所以需要重写拷贝构造，为指针分配内存
	//会调用赋值构造函数
	ttt1 = tttt;
	//下面会调用2次拷贝构造函数（一次是实参转形参，一次是返回值传临时变量） 和 赋值构造函数（返回值赋值给ttt1）
    //实参转形参实际上就是CopyTest mmm = tttt; 
	ttt1 = show(tttt);
	//下面会调用1次拷贝构造函数（实参转形参） 和 赋值构造函数（返回值赋值给ttt1）
	ttt1 = show1(tttt);

}
//结论
/*我们可以得出简单的结论：
1·初始化用一个函数进行赋值的时候会调用拷贝构造函数，
2·当初始化之后，后面通过=进行赋值的时候，会调用赋值构造函数，
3·函数传参如果不是引用而是对象的话就会调用拷贝构造函数。*/
//因此如果需要返回对象的时候，尽量使用返回值为引用，可以减少一次拷贝
//传递的参数如果是对象尽量使用引用，也可以减少一次拷贝