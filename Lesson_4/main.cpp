#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<deque>

using namespace std;
//
//Task 1
template<typename T>
void insert_sorted(vector<T>& vec, T val)
{
	auto it = find_if(vec.begin(), vec.end(), [&val](int num) {return (val <= num); });
	if (it == vec.end())
		return vec.push_back(val);
	
	vec.insert(it, val);
}

template<typename T1, typename T2>
void insertSorted(T1& cont, T2 val)
{
	auto it = find_if(cont.begin(), cont.end(), [&val](int num) {return (val <= num); });
	if (it == cont.end())
		return cont.push_back(val);

	cont.insert(it, val);
}

//Task 2


int main()
{
	{
		cout << "Task 1\n";
		vector<int> vec(10);
		generate(vec.begin(), vec.end(), []() {return rand() % 100; });
		sort(vec.begin(), vec.end());
		int val = 13;
		cout << "insert_sorted vector:\n";
		insert_sorted(vec, val);
		for (auto& i : vec)
			cout << i << ' ';
		cout << endl;

		list<int> lst(10);
		generate(lst.begin(), lst.end(), []() {return rand() % 100; });
		lst.sort();
		val = 90;
		cout << "\ninsertSorted list:\n";
		insertSorted(lst, val);
		for (auto& i : lst)
			cout << i << ' ';
		cout << endl;

		deque<float> deq(10);
		generate(deq.begin(), deq.end(), []() {return (rand() % 100) / 3.33333f; });
		sort(deq.begin(), deq.end());
		float fval = 2.3f;
		cout << "\ninsertSorted deque:\n";
		insertSorted(deq, fval);
		for (auto& i : deq)
			cout << i << ' ';
		cout << endl;
	}

	{
		cout << "\nTask 2\n";
		vector<float> analog(100);
		generate(analog.begin(), analog.end(), []() {return (rand() % 100) / 3.33333f; });
		int i = 1;
		cout << "Analog signal\n";
		for_each(analog.begin(), analog.end(), [&i](float elem) {cout << i << ": " << elem<<endl; i++; });
		cout << "\n\n";
		vector<int> digital(100);
		copy(analog.begin(), analog.end(), digital.begin());
		i = 1;
		cout << "Digital signal\n";
		for_each(digital.begin(), digital.end(), [&i](float elem) {cout << i << ": " << elem << endl; i++; });

		i = 0;
		float digErr{ 0 };
		auto lmb = [&digital,&i,&digErr](float val)
		{
			digErr += pow((val - digital[i]),2);
			++i;
		};

		for_each(analog.begin(), analog.end(), lmb);
		cout <<"\nDigital signal error = " <<digErr << endl;

	}
}