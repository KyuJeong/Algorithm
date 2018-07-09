#include <iostream>

#define MAX 100001

template <typename T>
void swp(T& data1, T& data2)
{
	T tmp = data1;
	data1 = data2;
	data2 = tmp;
}

template <typename T>
struct priority_queue
{
	T arr[MAX] = { 0 };
	int idx = 1;
	bool empty()
	{
		return idx == 1;
	}
	int size()
	{
		return idx;
	}
	void push(T data)
	{
		arr[idx++] = data;
		int cur = idx - 1;
		while (1)
		{
			if (cur == 1) break;
			int par = cur >> 1;
			if (arr[cur] < arr[par])
				swp(arr[cur], arr[par]);
			else break;
			cur = par;
		}
	}
	void pop()
	{
		if (idx == 1) return;

		arr[1] = arr[--idx];
		int cur = 1;
		int next;
		while (cur << 1 < idx)
		{
			next = cur;
			if (arr[next] > arr[cur << 1])
				next = cur << 1;

			if (cur << 1 | 1 < idx && arr[next] > arr[cur << 1 | 1])
				next = cur << 1 | 1;

			if (cur == next) break;
			swp(arr[cur], arr[next]);
			cur = next;
		}
	}
	T top()
	{
		if (idx == 1)
		{
			arr[1] = 0;
		}
		return arr[1];
	}
};

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue <double> pq;
	double tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			double c = pq.top();
			if (c == (int)c)
				cout << -(int)c << "\n";
			else
				cout << (int)c << "\n";
			pq.pop();
		}
		else
		{
			if (tmp > 0)
				pq.push(tmp + 0.1);
			else
				pq.push(-tmp);
		}
	}

	return 0;
}