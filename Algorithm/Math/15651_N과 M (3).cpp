#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;

int N, M;

inline void Solve(int cnt, int cur, vi v)
{
	if (cnt > M)
	{
		for (auto i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
		Solve(cnt + 1, i, v);
		v.pop_back();
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	vi v;

	Solve(1, 0, v);

	return 0;
}