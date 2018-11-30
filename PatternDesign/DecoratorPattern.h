/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	      Decorator Pattern     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

class Coffee
{
public:
	virtual unsigned int cost(void) = 0;
};

class Decorator
{
public:

private:
	Decorator * concreateObj;
};


