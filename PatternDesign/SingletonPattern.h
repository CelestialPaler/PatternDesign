/**
*  Pattern Design - Singleton Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     SingletonPattern.h
*  @brief    Pattern Design - Singleton Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.16
*/
#pragma once
#include <iostream>
#include <mutex>

std::mutex mutex;

/**
* @ brief The class of singleton.
*              The constructor has been set to be private, which means this class can`t be instantiated
*               by outside the scope.The copy constructor and the override of assignment operation  
*               have been banned.The static method GetInstance first check if the instance has already
*               been instantiated, if so, return the pointer to the instance, if not, instantiate it.
*/
class Singleton
{
public:
	static Singleton * GetInstance(void);
	
private:
	Singleton() {}
	Singleton(const Singleton & _singleton) = delete;
	Singleton & operator = (const Singleton & _singleton) = delete;
};

static Singleton * gpInstance = nullptr; // A global pointer pointed to the instance of a singleton

Singleton * Singleton::GetInstance(void)
{
	mutex.lock();
	if (gpInstance == nullptr)
		gpInstance = new Singleton();
	mutex.unlock();
	return gpInstance;
}

/**
 * @brief A example of singleton pattern.
 *            In this example, st1 and st2 are both trying to instantiate the singleton class, but only 
 *            when the first time GetInstance() is called, the instance is created.In this case, st1 and st2 
 *            are pointing to the same instance, which means the same addr.
 */
void Example(void)
{
	Singleton * st1 = Singleton::GetInstance();
	Singleton * st2 = Singleton::GetInstance();

	std::cout << "Address of st1 : " << st1 << std::endl;
	std::cout << "Address of st2 : " << st2 << std::endl;
}


