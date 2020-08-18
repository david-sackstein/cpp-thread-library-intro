#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

static mutex mutex1, mutex2;

void foo()
{
	lock_guard<mutex> lock1(mutex1);

	cout << "foo() holds mutex1\n";
	
	this_thread::sleep_for(1s);
	
	cout << "foo() is trying to get mutex2\n";

	lock_guard<mutex> lock2(mutex2);

	cout << "foo() holds mutex2 and will exit\n";
}

void bar()
{
	lock_guard<mutex> lock2(mutex2);

	cout << "bar() holds mutex2\n";

	this_thread::sleep_for(1s);

	cout << "bar() is trying to get mutex1\n";

	lock_guard<mutex> lock1(mutex1);

	cout << "bar() holds mutex1 and will exit\n";
}

void Deadlocks()
{
	cout << "\n================= 9. Deadlocks ===============\n";

	thread t1(foo);
	thread t2(bar);

	t1.join();
	t2.join();

	cout << "You will probably not see this\n";
}