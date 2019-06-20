/* Not solved */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long n, k;
long long num[64];
long long cnt[64];
long long max_value;
long long max_count;
long long total_count;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	vector <long long> v;
	priority_queue <long long> pq;

	num[0] = 1;
	for (int i = 1; i <= 64; i++)
	{
		num[i] = num[i - 1] * 2;
	}

	int idx = -1;
	while (n > 0)
	{
		idx++;
		if (n % 2 == 1)
		{
			pq.push(idx);
			cnt[idx]++;
			total_count++;
		}
		max_value = idx;
		
		n /= 2;
	}

	max_count = 1;

	if (pq.size() > k)
	{
		cout << "No";
		return 0;
	}
	
	while (pq.size() < k)
	{
		long long cur = pq.top();
		pq.pop();
		pq.push(cur - 1);
		pq.push(cur - 1);
	}

	cout << "Yes\n";
	while (pq.size() > 1)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << pq.top();

	return 0;
}