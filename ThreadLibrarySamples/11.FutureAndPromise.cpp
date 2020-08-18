#include <thread>
#include <iostream>
#include <future>

using namespace std;

static int AddDeferred(future<int> a, future<int> b)
{
	cout << "Waiting for arguments\n";
	
	return a.get() + b.get();
}

void FutureAndPromise()
{
	cout << "\n================= 11. Future and Promise ===============\n";

	promise<int> p1, p2;
	
	future<int> fu2 = async(AddDeferred, p1.get_future(), p2.get_future());

	std::this_thread::sleep_for(1s);

	p1.set_value(10);
	p2.set_value(32);

	cout << "Add using deferred async result is " << fu2.get() << endl;
}