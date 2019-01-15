/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	    Simple Factory Pattern     												      */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <iostream>
#include <string>

class Product
{
public:
	virtual void Method() = 0;
};

class ProductA : public Product
{
public:
	void Method(void)
	{
		std::cout << "This is a product A." << std::endl;
	}
};

class ProductB : public Product
{
public:
	void Method(void)
	{
		std::cout << "This is a product B." << std::endl;
	}
};

class SimpleFactory
{
public:
	Product * CreateProduct(std::string _type)
	{
		if (_type == "A")
			return new ProductA();
		else if (_type == "B")
			return new ProductB();
		else
			return new ProductA();
	}
};
