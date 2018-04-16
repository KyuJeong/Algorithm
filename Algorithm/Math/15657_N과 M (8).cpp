#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

int N, M;
vi num;

void Solve(int cnt, int cur, int _min, vi v)
{
	if (cnt > M)
	{
		for (int i = 0; i < M; i++)
		{
			int idx = v[i];
			cout << num[idx] << " ";
		}

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
	num.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> num[i];
	
	sort(num.begin(), num.end());

	vi v;

	Solve(1, 0, 1, v);

	return 0;
}