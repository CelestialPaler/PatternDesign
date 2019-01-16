/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	    Factory Method Pattern     											      */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <iostream>

// The interface of the Product class
class IProduct
{
public:
	virtual void Method(void) = 0;
};

class ProductC : public IProduct
{
public:
	void Method(void)
	{
		std::cout << "This is a product C." << std::endl;
	}
};

class ProductD: public IProduct
{
public:
	void Method(void)
	{
		std::cout << "This is a product D." << std::endl;
	}
};

// The interface of the Factory class
class IFactory
{
public:
	virtual IProduct * CreateProduct(void) = 0;
};

// two inplment of the interface 
class FactoryC : public IFactory
{
public:
	IProduct * CreateProduct(void)
	{
		return new ProductC();
	}
};

class FactoryD : public IFactory
{
public:
	IProduct * CreateProduct(void)
	{
		return new ProductD();
	}
};

