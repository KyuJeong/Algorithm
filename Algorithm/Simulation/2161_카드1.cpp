#include <iostream>
#include <deque>

using namespace std;

int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	deque <int> d;
	for (int i = 1; i <= N; i++)
	{
		d.push_front(i);
	}

	while (d.size() > 1)
	{
		cout << d.back() << " ";
		d.pop_back();
		int num = d.back();
		d.pop_back();
		d.push_front(num);
	}

	cout << d[0];

	return 0;
}