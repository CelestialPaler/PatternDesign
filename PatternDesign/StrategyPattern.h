/**
*  Pattern Design - Strategy Pattern                                                                                              
*  Copyright (C) 2015-2019 Celestial Tech  
*  For more please check our website: www.tianshicangxie.com                  
*  @file     StrategyPattern.h                                                                                                        
*  @brief    Pattern Design - Strategy Pattern                                                                                                                        
*  @author   Celestial Paler                                                                                                                               
*  @email    sun1106153343@hotmail.com                                                                                                                                                        
*  @date     2019.01.16                                                                                                                                                                                                                
*/
#pragma once
#include <iostream>

/**
 * @brief The interface of the Strategy class.
 */
class IStrategy
{
public:
	/**
	 * @brief The algorithm that implemented by concrete Strategy class.
	 */
	virtual void algorithm(void) = 0;
};

/**
 * @brief A concrete implementation of IStrategy.
 */
class StrategyA : public IStrategy
{
public:
	void algorithm(void) override
	{
		std::cout << "This is strategy A." << std::endl;
	}
};

/**
 * @brief Another concrete implementation of IStrategy.
 */
class StrategyB : public IStrategy
{
public:
	void algorithm(void) override
	{
		std::cout << "This is strategy B." << std::endl;
	}
};

/**
 * @brief A object that has a Strategy.
 *  The specific strategy will be injected when instantiating a new object.
 */
class Object
{
public:
	Object(IStrategy * _strategy) : pStrategy(_strategy) {}

	void Operation(void)
	{
		pStrategy->algorithm();
	}

private:
	IStrategy * pStrategy;
};

/**
 * @brief A example of strategy pattern.
 *            Objedct1 and objedct2 are instantiated from the same class, and they invoked the same
 *            method, but executed different strategy. 
 */
void Example(void)
{
	std::cout << "A example of strategy pattern : "<< std::endl;
	Object object1(new StrategyA());
	Object object2(new StrategyB());

	object1.Operation();
	object2.Operation();
}