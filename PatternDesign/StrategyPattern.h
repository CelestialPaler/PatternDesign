/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	       Strategy Pattern     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <iostream>

class Strategy
{
public:
	virtual void algorithm(void) = 0;
};

class StrategyA : public Strategy
{
public:
	void algorithm(void) override
	{
		std::cout << "This is strategy A" << std::endl;
	}
};

class StrategyB : public Strategy
{
public:
	void algorithm(void) override
	{
		std::cout << "This is strategy B" << std::endl;
	}
};

class Context 
{
public:
	Context(Strategy * _sty)
	{
		this->strategy = _sty;
	}

	void Operation(void)
	{
		strategy->algorithm();
	}

private:
	Strategy * strategy;
};

