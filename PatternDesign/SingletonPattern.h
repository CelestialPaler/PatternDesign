/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	      Singleton Pattern     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <mutex>

std::mutex mutex;

class Singleton
{
public:
	static Singleton * GetInstance(void);
	
private:
	Singleton() {}
	Singleton(const Singleton & _singleton) = delete;
	Singleton & operator = (const Singleton & _singleton) = delete;
};

static Singleton * instancePointer = nullptr;

Singleton * Singleton::GetInstance(void)
{
	mutex.lock();
	if (instancePointer == nullptr)
		instancePointer = new Singleton();
	mutex.unlock();
	return instancePointer;
}

