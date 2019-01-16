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
#include "SimpleFactoryPattern.h"
#include "FactoryMethodPattern.h"
#include "AbstractFactoryPattern.h"

void SingletonExample(void);
void ObserverExample(void);
void StrategyExample(void);
void SimpleFactoryExample(void);
void FactoryMethodExample(void);
void AbstractFactoryExample(void);

enum Patterns 
{
	SingletonPattern,
	ObserverPattern,
	StrategyPattern,
	SimpleFactoryPattern,
	FactoryMethodPattern,
	AbstractFactoryPattern
};

int main(int argc, char * argv[]) 
{
	switch (Patterns::AbstractFactoryPattern)
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
	case SimpleFactoryPattern:
		SimpleFactoryExample();
		break;
	case FactoryMethodPattern:
		FactoryMethodExample();
		break;
	case AbstractFactoryPattern:
		AbstractFactoryExample();
		break;
	default:
		break;
	}
}

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

void SimpleFactoryExample(void)
{
	SimpleFactory factory;
	Product * a = factory.CreateProduct("A");
	Product * b = factory.CreateProduct("B");

	a->Method();
	b->Method();
}

void FactoryMethodExample(void)
{
	FactoryC factoryC;
	FactoryD factoryD;
	IProduct * productC = factoryC.CreateProduct();
	IProduct * productD = factoryD.CreateProduct();
	productC->Method();
	productD->Method();
}

void AbstractFactoryExample(void)
{
	AbstractFactory1 absfactory1;
	absfactory1.CreateProductFamilyA()->Method();
	absfactory1.CreateProductFamilyB()->Method();

	AbstractFactory2 absfactory2;
	absfactory2.CreateProductFamilyA()->Method();
	absfactory2.CreateProductFamilyB()->Method();
}
