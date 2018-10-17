#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

struct Pt
{
	int d;
	map <int, int> m;
};

int n;
vector <Pt> arr;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	if (n <= 2)
	{
		cout << n;
		return 0;
	}
	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i].d;

	sort(arr.begin(), arr.end(), [](Pt& p1, Pt& p2) {
		return p1.d < p2.d;
	});

	int _max = 2;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int dif = arr[i].d - arr[j].d;
			auto it = arr[j].m.find(dif);
			if (it != arr[j].m.end())
			{
				arr[i].m[dif] = it->second + 1;
				_max = max(_max, it->second + 1);
			}
			else
				arr[i].m[dif] = 2;
		}
	}

	cout << _max;

	return 0;
}