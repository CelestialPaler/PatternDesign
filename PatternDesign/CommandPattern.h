/***************************************************************************************************/
/*								        		 			Pattern Design  														      */
/*								        		 	       Command Pattern     													  */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include <iostream>  

class Invoker
{
public:
	void Invoke(void);
};

class Receiver
{
public:
	void Action() 
	{ 
		std::cout << "Bake mutton" << std::endl;
	}
};

class ICommand
{
public:
	virtual void Execute() = 0;
protected:
	Receiver * pReceiver;
};

class CommandA :public ICommand
{
public:
	void ExecuteCommand() { }
};
