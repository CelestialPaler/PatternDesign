/**
*  Pattern Design - Factory Method Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     FactoryMethodPattern.h
*  @brief    Pattern Design - Factory Method Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.16
*/
#pragma once
#include <iostream>

/**
 * @brief The interface of the Product class.
 */
class IProduct
{
public:
	virtual void Method(void) = 0;
};

/**
 * @brief A concrete implementation of IStrategy.
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
 * @brief Another concrete implementation of IStrategy.
 */
class ProductB: public IProduct
{
public:
	void Method(void)
	{
		std::cout << "This is a product B." << std::endl;
	}
};

/**
 * @brief The interface of the Factory class.
 */
class IFactory
{
public:
	virtual IProduct * CreateProduct(void) = 0;
};

/**
 * @brief A concrete implementation of IFactory.
 */
class FactoryA : public IFactory
{
public:
	IProduct * CreateProduct(void)
	{
		return new ProductA();
	}
};

/**
 * @brief Another concrete implementation of IFactory.
 */
class FactoryB : public IFactory
{
public:
	IProduct * CreateProduct(void)
	{
		return new ProductB();
	}
};

/**
 * @brief A example of strategy pattern. 
 */
void Example(void)
{
	FactoryA factoryA;
	FactoryB factoryB;
	IProduct * productA = factoryA.CreateProduct();
	IProduct * productB = factoryB.CreateProduct();

	productA->Method();
	productB->Method();
}