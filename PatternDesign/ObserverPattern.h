/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	      Observer Pattern     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <vector>

class Observer
{
public:
	virtual void Update(const int _temp) = 0;
};

class Observable
{
public:
	virtual void Register(Observer * _ob) = 0;
	virtual void Unregister(Observer * _ob) = 0;

private:
	virtual void Notify(void) = 0;
};


class Phone : public Observer
{
public:
	void Update(const int _temp) override
	{
		std::cout << "New data arrived : " << _temp << std::endl;
	}
};

class WeatherStation : public Observable
{
public:
	void Register(Observer * _ob) override
	{
		subscribers.push_back(_ob);
	}

	void Unregister(Observer * _ob) override
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
		for (Observer * ob : subscribers)
			ob->Update(temperature);
	}
private:
	std::vector<Observer *> subscribers;
	int temperature;
};
