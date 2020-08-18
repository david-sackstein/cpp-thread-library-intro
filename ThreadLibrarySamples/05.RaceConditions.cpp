#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>

using namespace std;

static int sum = 0;
//static atomic<int> sum = 0;
static int iterCount = 1000000;
static std::mutex _mutex;

static void Increment()
{
	for (int i = 0; i < iterCount; i++) {
		++sum;
	}
}

//static void Increment()
//{
//	for (int i = 0; i < iterCount; i++) {
//		_mutex.lock();
//		++sum;
//		_mutex.unlock();
//	}
//}
//
//static void Increment()
//{
//	for (int i = 0; i < iterCount; i++) {
//		lock_guard<mutex> guard(_mutex);
//		++sum;
//	}
//}
//
//static void Increment()
//{
//	for (int i = 0; i < iterCount; i++) {
//		unique_lock<mutex> lock(_mutex);
//		++sum;
//	}
//}

void RaceConditionAutoIncrement()
{
	cout << "\n================= 5. RaceConditionAutoIncrement ===============\n";

	sum = 0;
	
	thread t1(Increment);
	thread t2(Increment);

	t1.join();
	t2.join();

	const auto expectedSum = 2 * iterCount;
	
	cout << "Got sum " << sum << " Expected " << expectedSum << "\n";
}