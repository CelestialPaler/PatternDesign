/**
*  Pattern Design - Abstract Factory Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     AbstractFactoryPattern.h
*  @brief    Pattern Design - Abstract Factory Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.16
*/
#pragma once
#include <iostream>

/**
 * @brief The interface of the ProductFamilyA class.
 */
class IProductFamilyA
{
public:
	virtual void Method(void) = 0;
};

/**
 * @brief A concrete implementation of IProductFamilyA.
 */
class ProductA1 : public IProductFamilyA
{
public:
	void Method(void) override
	{
		std::cout << "This is product1 of FamilyA" << std::endl;
	}
};

/**
 * @brief Another concrete implementation of IProductFamilyA.
 */
class ProductA2 : public IProductFamilyA
{
public:
	void Method(void) override
	{
		std::cout << "This is product2 of FamilyA" << std::endl;
	}
};

/**
 * @brief The interface of the ProductFamilyB class.
 */
class ProductFamilyB
{
public:
	virtual void Method(void) = 0;
};

/**
 * @brief A concrete implementation of IProductFamilyB.
 */
class ProductB1 : public ProductFamilyB
{
public:
	void Method(void) override
	{
		std::cout << "This is product1 of FamilyB" << std::endl;
	}
};

/**
 * @brief Another concrete implementation of IProductFamilyB.
 */
class ProductB2 : public ProductFamilyB
{
public:
	void Method(void) override
	{
		std::cout << "This is product2 of FamilyB" << std::endl;
	}
};

/**
 * @brief The interface of the AbstractFactory class.
 */
class IAbstractFactory
{
public:
	virtual IProductFamilyA * CreateProductFamilyA(void) = 0;
	virtual ProductFamilyB * CreateProductFamilyB(void) = 0;
};

/**
 * @brief A concrete implementation of IAbstractFactory.
 */
class AbstractFactory1 : public IAbstractFactory
{
public:
	IProductFamilyA * CreateProductFamilyA(void) override
	{
		return new ProductA1();
	}
	ProductFamilyB * CreateProductFamilyB(void) override
	{
		return new ProductB1();
	}
};

/**
 * @brief Another concrete implementation of IAbstractFactory.
 */
class AbstractFactory2 : public IAbstractFactory
{
public:
	IProductFamilyA * CreateProductFamilyA(void) override
	{
		return new ProductA2();
	}
	ProductFamilyB * CreateProductFamilyB(void) override
	{
		return new ProductB2();
	}
};

/**
 * @brief A example of abstract factory pattern.
 */
void Example(void)
{
	AbstractFactory1 absfactory1;
	absfactory1.CreateProductFamilyA()->Method();
	absfactory1.CreateProductFamilyB()->Method();

	AbstractFactory2 absfactory2;
	absfactory2.CreateProductFamilyA()->Method();
	absfactory2.CreateProductFamilyB()->Method();
}
