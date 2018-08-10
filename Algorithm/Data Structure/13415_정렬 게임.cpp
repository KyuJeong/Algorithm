#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second

typedef pair <int, int> pii;

int arr[100001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	deque <int> src;
	deque <int> dst;
	vector <pii> v;

	int n, k;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> k;
	k *= 2;
	int a;
	for (int i = 1; i <= k; i++)
	{
		cin >> a;
		v.push_back({ a,i });
	}

	sort(v.begin(), v.end(), [](const pii &p1, const pii &p2)
	{
		if (p1.first == p2.first)
			return p1.second > p2.second;
		return p1.first > p2.first;
	});

	for (int i = v[0].first + 1; i <= n; i++)
		dst.push_back(arr[i]);

	for (int i = 1; i <= v[0].first; i++)
		src.push_back(arr[i]);

	sort(src.begin(), src.end());

	pii pre = v[0];
	for (auto i : v)
	{
		if (i.snd < pre.snd) continue;
		if (pre.snd & 1) // 이전이 오름차순이었을때
		{
			int dif = pre.fst - i.fst;
			for (int i = 0; i < dif; i++)
			{
				dst.push_front(src.back());
				src.pop_back();
			}
		}
		else
		{
			int dif = pre.fst - i.fst;
			for (int i = 0; i < dif; i++)
			{
				dst.push_front(src.front());
				src.pop_front();
			}
		}
		pre = i;
	}

	if (!(pre.snd & 1))
		reverse(src.begin(), src.end());

	for (auto i : src)
		cout << i << " ";
	for (auto i : dst)
		cout << i << " ";

	return 0;
}