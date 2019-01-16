/**
*  Pattern Design - Simple Factory Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     SimpleFactoryPattern.h
*  @brief    Pattern Design - Simple Factory Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.16
*/
#pragma once
#include <iostream>

/**
 * @brief The interface of the Observer class.
 */
class IProduct
{
public:
	virtual void Method() = 0;
};

/**
 * @brief A concrete implementation of IProduct.
 */
class ProductA : public IProduct
{
public:
	void Method(void)
	{
		std::cout << "This is a product A." << std::endl;
	}
};

/**
 * @brief Another concrete implementation of IProduct.
 */
class ProductB : public IProduct
{
public:
	void Method(void)
	{
		std::cout << "This is a product B." << std::endl;
	}
};

/**
 * @brief The simple factory creates the object according to the pramater that passed into the 
 *             factory.
 */
class SimpleFactory
{
public:
	IProduct * CreateProduct(char _type)
	{
		if (_type == 'A')
			return new ProductA();
		else if (_type == 'B')
			return new ProductB();
		else
			return new ProductA();
	}
};

/**
 * @brief A example of simple factory pattern.
 */
void Example(void)
{
	SimpleFactory factory;
	IProduct * a = factory.CreateProduct('A');
	IProduct * b = factory.CreateProduct('B');

	a->Method();
	b->Method();
}