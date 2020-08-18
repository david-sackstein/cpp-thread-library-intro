#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;
using namespace chrono_literals;

/*
	using atto  = ratio<1, 1000000000000000000LL>;
	using femto = ratio<1, 1000000000000000LL>;
	using pico  = ratio<1, 1000000000000LL>;
	using nano  = ratio<1, 1000000000>;
	using micro = ratio<1, 1000000>;
	using milli = ratio<1, 1000>;
	using centi = ratio<1, 100>;
	using deci  = ratio<1, 10>;
	using deca  = ratio<10, 1>;
	using hecto = ratio<100, 1>;
	using kilo  = ratio<1000, 1>;
	using mega  = ratio<1000000, 1>;
	using giga  = ratio<1000000000, 1>;
	using tera  = ratio<1000000000000LL, 1>;
	using peta  = ratio<1000000000000000LL, 1>;
	using exa   = ratio<1000000000000000000LL, 1>;

    using nanoseconds  = duration<long long, nano>;
	using microseconds = duration<long long, micro>;
	using milliseconds = duration<long long, milli>;
	using seconds      = duration<long long>;
	using minutes      = duration<int, ratio<60>>;
	using hours        = duration<int, ratio<3600>>;

	template <class _Clock, class _Duration = typename _Clock::duration>
    class time_point { // represents a point in time
*/

void Chrono()
{
	cout << "\n================= 3. ChronoLibrary ===============\n";

	const steady_clock::time_point start = steady_clock::now();

	const steady_clock::time_point onesecondFromNow = start + seconds(1);
	const steady_clock::time_point twosecondsFromNow = onesecondFromNow + 1s;

	this_thread::sleep_until(twosecondsFromNow);
	this_thread::sleep_for(milliseconds(100));

	const steady_clock::time_point end = steady_clock::now();

	const duration<int64_t, ratio<1, 1000000000>> diff = end - start;
	const nanoseconds diffNano = diff;

	const int64_t elapsedMsec = duration_cast<milliseconds>(diff).count();

	cout << elapsedMsec << " msec have elapsed\n";
}