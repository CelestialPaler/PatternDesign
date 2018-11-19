/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 				Examples     														          */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/

#include <iostream>

#include "SingletonPattern.h"

void SingletonExample(void)
{
	Singleton * st1 = Singleton::GetInstance();
	Singleton * st2 = Singleton::GetInstance();
	std::cout << "Address of st1 : " << st1 << std::endl;
	std::cout << "Address of st2 : " << st2 << std::endl;
}

enum Patterns 
{
	SingletonPattern,
	ObserverPattern
};

int main(int argc, char * argv[]) 
{
	switch (Patterns()) 
	{
	case SingletonPattern:
		SingletonExample();
		break;
	case ObserverPattern:
		break;
	default:
		break;
	}
}

