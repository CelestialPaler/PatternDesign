/**
*  Pattern Design - Facade Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     FacadePattern.h
*  @brief    Pattern Design - Facade Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.18
*/

#pragma once
#include <iostream>

/**
 * @brief A lots of messive-interacting parts and multiple interfaces.
 */
class PartA
{
public:
	void whcriuwhciueh(void)
	{
		std::cout << "Operation A1." << std::endl;
	}
	void sajdiofjsaoijfods(void)
	{
		std::cout << "Operation A2." << std::endl;
	}
};

class PartB
{
public:
	void jfoisaejfoias(void)
	{
		std::cout << "Operation B." << std::endl;
	}
};

class PartC
{
public:
	void spiafdjsfsoij(void)
	{
		std::cout << "Operation C." << std::endl;
	}
};

/**
 * @brief The facade provides a uniformed interface to the client, hide knowladges from them.
 */
class Facade : private PartA, PartB, PartC
{
public:
	Facade(PartA *_pa, PartB * _pb, PartC * _pc)
	{
		this->_pPartA = _pa;
		this->_pPartB = _pb;
		this->_pPartC = _pc;
	}
	void Operation1(void)
	{
		_pPartA->whcriuwhciueh();
	}
	void Operation2(void)
	{
		_pPartA->sajdiofjsaoijfods();
	}
	void Operation3(void)
	{
		_pPartB->jfoisaejfoias();
	}
	void Operation4(void)
	{
		_pPartC->spiafdjsfsoij();
	}
private:
	PartA *_pPartA;
	PartB *_pPartB;
	PartC *_pPartC;
};

/**
 * @brief A example of facade pattern.
 *            Silly names of functions and variables which seems to be overkilled are just intended to 
 *            illustrate that massive functions and interfaces can cause confusion and inefficiency.But 
 *            with facade, it can be clear and easy for client to interact with all the parts of the system
 *            in a unified manner.
 */
void Example(void)
{
	PartA sadffwa;
	PartB tgyjtdj;
	PartC fgdhdtrf;

	// Without facade
	// Hard to tell what the maddness it is.
	sadffwa.whcriuwhciueh();
	sadffwa.sajdiofjsaoijfods();
	tgyjtdj.jfoisaejfoias();
	fgdhdtrf.spiafdjsfsoij();

	// With facade
	// Easy peasy lemon squeezy
	Facade facade(&sadffwa, &tgyjtdj, &fgdhdtrf);
	facade.Operation1();
	facade.Operation2();
	facade.Operation3();
	facade.Operation4();
}	