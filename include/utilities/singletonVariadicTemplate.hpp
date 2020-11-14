 ///
 /// @file    singletonTemplate.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 17:10:26
 ///
#ifndef __singletonTemplate__
#define __singletonTemplate__
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <pthread.h>
using std::cout;
using std::endl;
using std::vector;
#if 0
class Student{
public:
	Student(){ cout<<"Student()"<<endl; }
	Student(int x,int y)
	:_age(x)
	,_height(y)
	{
		cout<<"Student(,)"<<endl;
	}

	~Student(){
		cout<<"~Student"<<endl;
	}
//	private:
		int _age;//
		int _height;
};
#endif

template<typename T> class Singleton{
	class AutoRelease{
		public:
		AutoRelease(){ cout<<"AutoRelease()"<<endl; }
		~AutoRelease(){ 
			cout<<"~AutoRelease()"<<endl;
			destory();
		}
	};
public:
	template<typename... Args>	static T * getInstance(Args ... args){
		if(NULL==_pInstance){
			_auto;//未使用，编译器优化，该对象的静态区未构建
			_pInstance=new T(args...);
		}
		return _pInstance;
	}
//	Singleton * getInstance();
	static void destory(){
		if(NULL!=_pInstance)
			delete _pInstance;
	}
private:
		Singleton(){cout<<"Singleton()"<<endl;}
		~Singleton(){cout<<"~Singleton()"<<endl;}
private:
//		static Singleton * _pInstance;
		static T * _pInstance;
		static AutoRelease _auto;

//必须静态，控制执行的次数
		static pthread_once_t once_control;//
};

template<typename T> pthread_once_t Singleton<T>::once_control = PTHREAD_ONCE_INIT;
//lazy mode + pthread_once()
//template<typename T>	T * Singleton<T>::_pInstance=NULL;
//
//eager mode  可以静态成员初始化时，调用getInstance()
template<typename T>	T * Singleton<T>::_pInstance=NULL;
//2. typename? 为什么 : template<typename T> Singleton<T>::AutoRelease Singleton<T>::_atuo;
template<typename T> typename Singleton<T>::AutoRelease Singleton<T>::_auto;

#endif
