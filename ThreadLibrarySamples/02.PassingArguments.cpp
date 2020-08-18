#include <thread>
#include <iostream>

using namespace std;

static void ByValue(int value)
{
	cout << "By value: value = " << value << endl;
}

static void ByReference(int& value)
{
	cout << "By reference value = " << value++ << endl;
}

void PassingArguments()
{
	cout << "\n================= 2. PassingArguments ===============\n";

	int value = 42;

	thread t1(ByValue, value);
	t1.join();

	// Does not compile
	//thread t2(ByReference, value);
	//t2.join();

	//cout << "After call value = : " << value << endl;

	thread t3(ByReference, ref(value));
	t3.join();

	cout << "After call value = " << value << endl;
}