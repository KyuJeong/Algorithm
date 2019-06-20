#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector <int> a;
vector <ll> sum;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	a.resize(n);
	sum.resize(n);

	for (int i=0; i<n; i++)
		cin >> a[i];

	sum[0] = a[0];
	cout << "0";
	
	priority_queue <int> pq;
	pq.push(a[0]);
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		if (sum[i] > m)
		{
			priority_queue <int> tmp = pq;
			ll tmp_sum = sum[i];
			int cnt = 0;
			while (tmp_sum > m)
			{
				tmp_sum -= tmp.top();
				tmp.pop();
				cnt++;
			}
			cout << " " << cnt;
		}
		else
			cout << " 0";
		pq.push(a[i]);
	}

	return 0;
}