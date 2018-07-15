#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
	while (1)
	{
		int r = a%b;
		/*나머지가 0이라면*/

		if (r == 0)
			return b;

		/*gcd(a,b) = gcd(b,r)*/
		a = b;
		b = r;
	}
	return a;
}

int N, M;
bool Prime[100001];
vector <int> v[100001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	if (M < N - 1)
	{
		cout << "Impossible";
		return 0;
	}

	int cnt = 0;

	bool pos = false;
	for (int i = 2; i <= N; i++)
	{
		v[1].push_back(i);
		cnt++;
		if (cnt == M)
		{
			pos = true;
			break;
		}
	}

	if (pos)
	{
		cout << "Possible\n";
		for (auto j : v[1])
		{
			cout << 1 << " " << j << "\n";
		}
		return 0;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			if (j % i == 0)
				continue;
			if (gcd(j, i) == 1)
			{
				cnt++;
				v[i].push_back(j);
			}
			if(cnt == M)
			{
				pos = true;
				break;
			}
		}
		if (pos)
			break;
	}

	if (pos)
	{
		cout << "Possible\n";
		for (int i = 1; i <= N; i++)
		{
			for (auto j : v[i])
			{
				cout << i << " " << j << "\n";
			}
		}
	}
	else
		cout << "Impossible\n";

	return 0;
}