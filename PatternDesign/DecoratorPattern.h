/**
*  Pattern Design - Decorator Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     DecoratorPattern.h
*  @brief    Pattern Design - Decorator Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.17
*/
#pragma once
#include <iostream>

/**
 * @brief The interface of the Object class.
 */
class IObject
{
public:
	virtual ~IObject(void) {}
	virtual void Operation(void) = 0;
};

/**
 * @brief The base object that was wrapped by decorators.
 */
class BaseObject : public IObject
{
public:
	~BaseObject(void) override
	{
		std::cout << "BaseObject-deleted ";
	}
	void Operation(void) override 
	{
		std::cout << "BaseObject ";
	}
};

/**
* @brief The decorator that wraps the base object or another decorator.
*/
class Decorator : public IObject
{
public:
	Decorator(IObject * _wrappee) 
	{
		pWrappee = _wrappee;
	}
	~Decorator(void) 
	{
		delete pWrappee;
	}
	void Operation(void) override
	{
		pWrappee->Operation();
	}
private:
	IObject * pWrappee;
};

/**
* @brief A concrete implementation of Decorator.
*/
class DecoratorA : public Decorator
{
public:
	DecoratorA(IObject * _wrappee) : Decorator(_wrappee) {}
	~DecoratorA(void)
	{
		std::cout << "DecoratorA-deleted ";
	}
	void Operation(void)
	{
		Decorator::Operation();
		std::cout << "DecoratorA ";
	}
};

/**
* @brief A concrete implementation of Decorator.
*/
class DecoratorB : public Decorator
{
public:
	DecoratorB(IObject * _wrappee) : Decorator(_wrappee) {}
	~DecoratorB(void)
	{
		std::cout << "DecoratorB-deleted ";
	}
	void Operation(void)
	{
		Decorator::Operation();
		std::cout << "DecoratorB ";
	}
};

/**
* @brief A concrete implementation of Decorator.
*/
class DecoratorC : public Decorator
{
public:
	DecoratorC(IObject * _wrappee) : Decorator(_wrappee) {}
	~DecoratorC(void)
	{
		std::cout << "DecoratorC-deleted ";
	}
	void Operation(void)
	{
		Decorator::Operation();
		std::cout << "DecoratorC ";
	}
};

/**
 * @brief A example of decorator pattern.
 */
void Example(void)
{
	IObject * test = new DecoratorC(new DecoratorB(new DecoratorA(new BaseObject)));
	test->Operation();
	std::cout << std::endl;
	delete test;
}