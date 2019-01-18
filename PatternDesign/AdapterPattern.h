/**
*  Pattern Design - Adapter Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     AdapterPattern.h
*  @brief    Pattern Design - Adapter Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.18
*/

#pragma once
#include <iostream>

/**
 * @brief The new interface of the we want to use for future.
 */
class INewObject
{
public:
	virtual void NewOperation(int _n, int _m) = 0;
};

/**
 * @brief The old interface that we`v got for now.
 *             Its usually some kinda lagecy code in old lib or previous project.
 */
class OldObject
{
public:
	void OldOperation(int _n)
	{
		std::cout << _n << std::endl;
	}
};

/**
 * @brief The adapter we created for translate new interface into old interface, in other words, 
 *             adapt new interface to the old one.
 */
class Adapter : public INewObject, private OldObject
{
public:
	Adapter(OldObject * _p) : pAdaptee(_p) {}

	void NewOperation(int _n, int _m) override
	{
		pAdaptee->OldOperation(_n + _m);
	}
private:
	OldObject * pAdaptee;
};

/**
 * @brief A example of adapter pattern.
 *            In this case, the client wants to use the new interface INewObject, after usign a adapter
 *            client can call NewOperation without knowing that it`s actually handled by the old lagecy
 *            code.
 */
void Example(void)
{
	OldObject oldObj;

	INewObject * newObj = new Adapter(&oldObj);

	newObj->NewOperation(1, 1);

	delete newObj;
}
