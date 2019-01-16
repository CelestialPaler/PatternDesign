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

class ProductFamilyA
{
public:
	virtual void Method(void) = 0;
};

class ProductA1 : public ProductFamilyA
{
public:
	void Method(void) override
	{
		std::cout << "This is product1 of FamilyA" << std::endl;
	}
};

class ProductA2 : public ProductFamilyA
{
public:
	void Method(void) override
	{
		std::cout << "This is product2 of FamilyA" << std::endl;
	}
};

class ProductFamilyB
{
public:
	virtual void Method(void) = 0;
};

class ProductB1 : public ProductFamilyB
{
public:
	void Method(void) override
	{
		std::cout << "This is product1 of FamilyB" << std::endl;
	}
};

class ProductB2 : public ProductFamilyB
{
public:
	void Method(void) override
	{
		std::cout << "This is product2 of FamilyB" << std::endl;
	}
};

// The interface of the Abstract Factory class 
class IAbstractFactory
{
public:
	virtual ProductFamilyA * CreateProductFamilyA(void) = 0;
	virtual ProductFamilyB * CreateProductFamilyB(void) = 0;
};

class AbstractFactory1 : public IAbstractFactory
{
public:
	ProductFamilyA * CreateProductFamilyA(void) override
	{
		return new ProductA1();
	}
	ProductFamilyB * CreateProductFamilyB(void) override
	{
		return new ProductB1();
	}
};

class AbstractFactory2 : public IAbstractFactory
{
public:
	ProductFamilyA * CreateProductFamilyA(void) override
	{
		return new ProductA2();
	}
	ProductFamilyB * CreateProductFamilyB(void) override
	{
		return new ProductB2();
	}
};


void AbstractFactoryExample(void)
{
	AbstractFactory1 absfactory1;
	absfactory1.CreateProductFamilyA()->Method();
	absfactory1.CreateProductFamilyB()->Method();

	AbstractFactory2 absfactory2;
	absfactory2.CreateProductFamilyA()->Method();
	absfactory2.CreateProductFamilyB()->Method();
}
