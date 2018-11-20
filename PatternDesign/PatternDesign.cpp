/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 				Examples     														          */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/

#include <iostream>

#include "SingletonPattern.h"
#include "ObserverPattern.h"
#include "StrategyPattern.h"

void SingletonExample(void)
{
	Singleton * st1 = Singleton::GetInstance();
	Singleton * st2 = Singleton::GetInstance();
	std::cout << "Address of st1 : " << st1 << std::endl;
	std::cout << "Address of st2 : " << st2 << std::endl;
}

void ObserverExample(void)
{
	std::cout << "A example of observer pattern : \n"
		<< "Phones that subscribed a weather station for temperature." 
		<< std::endl;
	WeatherStation weatherStation;
	Phone phone1;
	Phone phone2;

	weatherStation.Register(&phone1);
	weatherStation.Register(&phone2);

	weatherStation.SetTemperature(28);

	Phone phone3;
	weatherStation.Register(&phone3);

	weatherStation.SetTemperature(25);

	weatherStation.Unregister(&phone1);
	weatherStation.Unregister(&phone2);

	weatherStation.SetTemperature(27);
}

void StrategyExample(void)
{
	std::cout << "A example of strategy pattern : \n"
		<< "Context1 and Context2 invoked the same method but with different strategy."
		<< std::endl;
	Context context1(new StrategyA());
	Context context2(new StrategyB());
	context1.Operation();
	context2.Operation();
}

enum Patterns 
{
	SingletonPattern,
	ObserverPattern,
	StrategyPattern
};

int main(int argc, char * argv[]) 
{
	switch (Patterns::StrategyPattern)
	{
	case SingletonPattern:
		SingletonExample();
		break;
	case ObserverPattern:
		ObserverExample();
		break;
	case StrategyPattern:
		StrategyExample();
		break;
	default:
		break;
	}
}
