#include <thread>
#include <iostream>

using namespace std;

static void DidYouSeeThis()
{
	cout << "Did you see this?" << endl;
}

void JoinDetach()
{
	cout << "\n================= 4. JoinDetach ===============\n";

	thread t1(DidYouSeeThis);

	// If you comment this out the dtor of t1 will call terminate()
	
	t1.detach();

	cout << "exiting ...\n";

	this_thread::sleep_for(chrono::milliseconds(100));

	// Recommended way to call join
	
	if (t1.joinable())
	{
		t1.join();
	}
}