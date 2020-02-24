#include "IObserver.h"
#include "ISubject.h"

#include <iostream>
#include <utility>
#include <vector>

class Subject : public ISubject
{
public:
	void Attach(IObserver& o) override
	{
		observers.emplace_back(o);
	}

	void Deatach(IObserver& o) override
	{
		observers.erase(std::find_if(observers.begin(), observers.end(), [&](const std::reference_wrapper<IObserver> i)
			{
				return &i.get() == &o;
			}));
	}

	void Notify() override
	{
		for (auto& observer : observers)
		{
			observer.get().Notify();
		}
	}

private:
	std::vector<std::reference_wrapper<IObserver>> observers;
};

class IOObserver : public IObserver
{
public:
	IOObserver(std::string value) :value(std::move(value)) {}

	void Notify() override
	{
		std::cout << value << std::endl;
	}

private:
	const std::string value;
};

int main(int argc, char* argv[])
{
	Subject subj;

	IOObserver o1("Test1");
	IOObserver o2("Test2");

	subj.Attach(o1);
	subj.Attach(o2);

	subj.Notify();

	subj.Deatach(o2);

	subj.Notify();

	return 0;
}
