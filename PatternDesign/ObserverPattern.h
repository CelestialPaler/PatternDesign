/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	      Observer Pattern     														  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <vector>

class Observable
{
public:
	void Register(Observer & const _ob) {
		subscribers.push_back(_ob);
	}

	void Unregister(Observer & const _ob) {
		subscribers.erase(std::find(subscribers.cbegin(), subscribers.cend(), _ob));
	}

private:
	virtual void notify(void) {
		for (Observer & ob : subscribers)
			ob.Update();
	}

	std::vector<Observer & const> subscribers;
};

class Observer
{
public:
	virtual void Update(void) = 0;
private:
	virtual void GetState(void) = 0;
};