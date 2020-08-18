#include <iostream>
#include <thread>
#include <queue>
#include <random>
#include <mutex>

using namespace std;

namespace {
	class ThreadSafeQueue
	{
	public:

		void Push(int value)
		{
			lock_guard<mutex> guard(_mutex);
			_queue.push(value);
		}

		int Pop()
		{
			while (IsEmpty())
			{
				//cout << ".";
				this_thread::sleep_for(100ms);
			}
			lock_guard<mutex> guard(_mutex);
			const int value = _queue.front();
			_queue.pop();
			return value;
		}

		bool IsEmpty()
		{
			lock_guard<mutex> guard(_mutex);
			return _queue.empty();
		}

	private:

		queue<int> _queue;
		mutex _mutex;
	};
}

static ThreadSafeQueue _queue;

static void RandomSleep()
{
	const auto sleepMsec = rand() % 500;
	this_thread::sleep_for(chrono::milliseconds(sleepMsec));
}

static void Produce()
{
	for (int i = 10; i >= 0; i--)
	{
		RandomSleep();
		
		_queue.Push(i);
		cout << "Pushed " << i << endl;
	}
}

static void Consume()
{
	for (int i = 0; i < 10;) 
	{
		const int value = _queue.Pop();
		cout << "Popped " << value << endl;
		i++;
	}
}

void ProducerConsumerBusyLoop()
{
	cout << "\n================= 8. Busy Loop ===============\n";

	thread t1(Produce);
	thread t2(Consume);
	t1.join();
	t2.join();
}