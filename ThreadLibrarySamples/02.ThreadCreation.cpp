#include <thread>
#include <iostream>

using namespace std;

struct FunctionObject
{	
	void operator()() const
	{
		cout << "Thread: " << this_thread::get_id() << " in function object" << endl;
	}
};

static void function()
{
	cout << "Thread: " << this_thread::get_id() << " in function" << endl;
}

void ThreadCreation()
{
	cout << "\n================= 1. ThreadCreation ===============\n";
	
	cout << "Main thread: " << this_thread::get_id() << endl;

	// Using function
	thread t1(function);
	t1.join();

	// Using function object
	FunctionObject fo;
	thread t2(fo);
	t2.join();

	// Using lambda
	auto lambda = []
	{
		cout << "Thread: " << this_thread::get_id() << " in lambda" << endl;
	};
	
	thread t3(lambda);
	t3.join();
}