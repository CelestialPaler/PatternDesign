/**
*  Pattern Design - Command Pattern
*  Copyright (C) 2015-2019 Celestial Tech
*  For more please check our website: www.tianshicangxie.com
*  @file     CommandPattern.h
*  @brief    Pattern Design - Command Pattern
*  @author   Celestial Paler
*  @email    sun1106153343@hotmail.com
*  @date     2019.01.17
*/

#include <iostream>
#include <vector>

/**
 * @brief The interface of the Command class.
 */
class ICommand
{
public:
	virtual void Execute(void) = 0;
};

/**
 * @brief Invoker is the class that make a request and send a command.
 */
class Invoker
{
public:
	void Execute(ICommand * _command)
	{
		if (_command != nullptr)
		{
			commandHistory.push_back(_command);
			_command->Execute();
		}
	}

private:
	std::vector<ICommand *> commandHistory;
};

/**
 * @brief Reciever is the class that listens to a command and actrually perform an action.
 */
class Reciever
{
public:
	void Action1(void)
	{
		std::cout << "Performing action 1." << std::endl;
	}

	void Action2(void)
	{
		std::cout << "Performing action 2." << std::endl;
	}
};

/**
 * @brief A concrete implementation of ICommand.
 */
class Command1 : public ICommand
{
public:
	Command1(Reciever * _reciever)
	{
		pReciever = _reciever;
	}

	void Execute(void)
	{
		pReciever->Action1();
	}

private:
	Reciever * pReciever;
};

/**
 * @brief Another concrete implementation of ICommand.
 */
class Command2 : public ICommand
{
public:
	Command2(Reciever * _reciever)
	{
		pReciever = _reciever;
	}

	void Execute(void)
	{
		pReciever->Action2();
	}

private:
	Reciever * pReciever;
};

/**
 * @brief A example of command pattern.
 */
void Example(void)
{
	Reciever * reciever = new Reciever();
	ICommand * command1 = new Command1(reciever);
	ICommand * command2 = new Command2(reciever);
	Invoker * invoker = new Invoker();

	invoker->Execute(command1);
	invoker->Execute(command2);

	delete reciever;
	delete command1;
	delete command2;
	delete invoker;
}