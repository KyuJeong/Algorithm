#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

typedef tuple <int, int, int> tiii;
typedef tuple <int, int, int, int> tiiii;

vector <tiiii> v;

int N, K;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int idx;
	int g, s, b;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> idx >> g >> s >> b;
		if (idx == K)
			idx = 1e9;
		v.push_back({ g,s,b,idx });
	}

	sort(v.begin(), v.end());

	reverse(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		if (get<3>(v[i]) == 1e9)
		{
			cout << i + 1 << "\n";
			break;
		}
	}
	
	return 0;
}