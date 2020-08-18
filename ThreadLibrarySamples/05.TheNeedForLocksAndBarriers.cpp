#include <iostream>
#include <thread>

using namespace std;

void TheNeedForLocksAndBarriers()
{
	cout << "\n================= 5. TheNeedForLocksAndBarriers ===============\n";

	bool complete = false;
	thread t([&]
	{
		bool toggle = false;
		while (!complete) {
			toggle = !toggle;
		}
	});
	this_thread::sleep_for(1s);
	
	complete = true;
	t.join();        // May block indefinitely
}

void ReorderingExample()
{
	// See here https://preshing.com/20120515/memory-reordering-caught-in-the-act/
}