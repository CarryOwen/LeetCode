#include "iostream"
using namespace std;
/*如果不希望类成员函数修改类对象的状态，那么这个成员函数一般会被const修饰
非静态成员函数后面加const（加到非成员函数或静态成员后面会产生编译错误），
表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，任意修改它所在的类的成员的操作都是不允许的（因为隐含了对this指针的const引用）；
唯一的例外是对于mutable修饰的成员。
加了const的成员函数可以被非const对象和const对象调用，
但不加const的成员函数只能被非const对象调用。
*/
class A {
public:
	static int a;
	int b;
	void changea(int i) const {//与下面的不同，即使是const函数，静态成员变量不属于任何对象，所以可以修改。
		this->a = i;
	}
	/*
	void changeb(int j) const {
		this->b = j;  //这里的this是const，也就是说，this指向的值是不允许被修改的，所以会报错
        //但是如果在int前面加了mutable关键词则可以修改，即 mutable int b，这时候修改用this->b=j是可以的
	}
	*/
};
int A::a;

int main() {
	A temp0;
	temp0.changea(6);
}
