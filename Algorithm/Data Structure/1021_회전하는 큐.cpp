#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 52

template <typename T>
struct queue
{
	T arr[MAX + 1] = { 0 };
	int idx;
	queue() : idx(0) {}

	int size() { return idx; }

	void push(T data)
	{
		if (idx == MAX) return;
		arr[idx++] = data;
	}

	T pop()
	{
		if (idx == 0) return -1;
		T ret = arr[0];
		idx--;
		for (int i = 0; i < idx; i++)
			arr[i] = arr[i + 1];
		return ret;
	}

	int index(T x)
	{
		for (int i = 0; i < idx; i++)
			if (arr[i] == x)
				return i;
	}
};

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	queue <int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	int tmp;
	int cnt = 0;
	while (m--)
	{
		cin >> tmp;
		int idx = q.index(tmp);
		cnt += min(idx, q.size() - idx);

		while (idx--) q.push(q.pop());
		q.pop();
	}

	cout << cnt;

	return 0;
}