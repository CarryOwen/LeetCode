#pragma once
#include <mutex>
#include <thread>
#include <iostream>
#include <stdio.h>
using namespace std;
class MutexTest
{
private:
	/*
	静态成员变量：

	所有对象共享同一份数据
	在编译阶段分配内存
	类内声明，类外初始化
	*/
	static mutex _mutex;
	static int _val1;
	static int _val2;

public:
	/*静态成员函数：

	所有对象共享同一个函数
	静态成员函数只能访问静态成员变量*/
	static void DoOne()
	{	
		for (int i = 0; i < 10000000; i++)
		{
			_val2++;
		}
		printf("val2 thread %d value: %d\n",this_thread::get_id(), _val2); //cout也是线程不安全，不能保证整个cout不被其他线程终端
		_mutex.lock();
		for (int i = 0; i < 10000000; i++)
		{
			_val1++;
		}
		printf("val1 thread %d mutexValue: %d\n", this_thread::get_id(), _val1); 
		_mutex.unlock();
		
	}
	void DoTest()
	{
		thread thread1(DoOne);
		thread thread2(DoOne);
		thread1.join();
		thread2.join();
	}
};
mutex MutexTest::_mutex;
int MutexTest::_val1=0;
int MutexTest::_val2=0;
int main()
{
    MutexTest mut;
    mut.DoTest();
    system("pause");
    return 0;
}