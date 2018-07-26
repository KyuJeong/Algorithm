#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

vi arr;
vi idx;
int cnt[101];
bool check[101];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	if (n > m)
	{
		cout << "0";
		return 0;
	}

	int tmp;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
		if (!check[tmp]) idx.push_back(tmp);
		check[tmp] = true;
	}

	sort(arr.begin(), arr.end());
	sort(idx.begin(), idx.end());

	for (auto i : arr)
	{
		cnt[i]++;
	}

	int i;
	for (i = 1; i <= 100; i++)
	{
		tmp = 0;
		for (auto j : idx)
		{
			tmp += cnt[j] / i;
		}
		if (tmp < n) break;
	}

	cout << i - 1;

	return 0;
}
