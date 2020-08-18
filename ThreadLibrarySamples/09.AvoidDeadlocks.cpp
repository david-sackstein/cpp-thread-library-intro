#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

static mutex mutex1, mutex2;

static void foo()
{
	lock(mutex1, mutex2);

	cout << "foo() holds mutex1 and mutex2\n";

	this_thread::sleep_for(1s);

	//lock_guard<mutex> guard1(mutex1, adopt_lock);
	//lock_guard<mutex> guard2(mutex2, adopt_lock);
	mutex1.unlock();
	mutex2.unlock();
}

static void bar()
{
	lock(mutex1, mutex2);

	cout << "bar() holds mutex1 and mutex2\n";

	this_thread::sleep_for(1s);

	mutex1.unlock();
	mutex2.unlock();
}

void SolveDeadlocks()
{
	cout << "\n================= 9. Solve Deadlocks ===============\n";

	thread t1(foo);
	thread t2(bar);

	t1.join();
	t2.join();

	cout << "You will see this now\n";
}