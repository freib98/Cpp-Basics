#include "ISubject.h"

void ISubject::Register(IObserver& o)
{
	observers.push_back(o);
}

void ISubject::Deregister(IObserver& o)
{
}

void ISubject::Notify()
{
	for (auto& o : observers)
	{
		o.Notify();
	}
}
