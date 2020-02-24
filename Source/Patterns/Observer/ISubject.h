#pragma once

#include "IObserver.h"

class IObserver;

class ISubject
{
public:
	virtual void Attach(IObserver&) = 0;
	virtual void Deatach(IObserver&) = 0;
	virtual void Notify() = 0;
};
