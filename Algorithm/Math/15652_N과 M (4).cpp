#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

int N, M;

void Solve(int cnt, int cur, int _min, vi v)
{
	if (cnt > M)
	{
		for (auto i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = _min; i <= N; i++)
	{
		v.push_back(i);
		Solve(cnt + 1, i, i, v);
		v.pop_back();
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	vi v;

	Solve(1, 0, 1, v);

	return 0;
}