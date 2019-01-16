/**
*  Pattern Design - Observer Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     ObserverPattern.h
*  @brief    Pattern Design - Observer Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.16
*/
#pragma once
#include <iostream>
#include <vector>

/**
 * @brief The interface of the Observer class.
 */
class IObserver
{
public:
	virtual void Update(const int _temp) = 0;
};

/**
 * @brief The interface of the Observable class.
 */
class IObservable
{
public:
	virtual void Register(IObserver * _ob) = 0;
	virtual void Unregister(IObserver * _ob) = 0;

private:
	virtual void Notify(void) = 0;
};

/**
 * @brief A concrete implementation of IObserver.
 */
class Phone : public IObserver
{
public:
	void Update(const int _temp) override
	{
		std::cout << "New data arrived : " << _temp << std::endl;
	}
};

/**
 * @brief A concrete implementation of IObservable.
 */
class WeatherStation : public IObservable
{
public:
	void Register(IObserver * _ob) override
	{
		subscribers.push_back(_ob);
	}

	void Unregister(IObserver * _ob) override
	{
		subscribers.erase(std::find(subscribers.cbegin(), subscribers.cend(), _ob));
	}

public:
	void SetTemperature(const int _temp)
	{
		this->temperature = _temp;
		this->Notify();
	}

private:
	void Notify(void) override
	{
		for (IObserver * ob : subscribers)
			ob->Update(temperature);
	}

private:
	std::vector<IObserver *> subscribers;
	int temperature;
};

/**
 * @brief A example of observer pattern.
 *            In this case, shows phones that subscribed to a weather station for temperature.
 */
void Example(void)
{
	std::cout << "A example of observer pattern : " << std::endl;
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