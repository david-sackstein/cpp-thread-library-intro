#include <thread>
#include <iostream>
#include <future>

using namespace std;

static int Add(int a, int b)
{
	return a + b;
}

static void AddReturnByRef(int a, int b, int& result)
{
	result = a + b;
}

void ReturningValueWithAsync()
{
	cout << "\n================= 10. Returning a value with async ===============\n";

	int result;
	
	thread t1(AddReturnByRef, 10, 32, std::ref(result));
	t1.join();

	cout << "AddReturnByRef result is " << result << endl;

	future<int> fu1 = async(Add, 10, 32);
	
	cout << "Add using async, result is " << fu1.get() << endl;
}