#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

int N, M;
vector <pii> edge;

void Solve()
{
	vi arr(N);
	for (int i = 0; i < N; i++)
		arr[i] = i;

	int ans = 1e9;
	vi tmp;

	do
	{
		if (arr[0] > arr[N - 1])
			continue;
		int sum = 0;
		for (auto i : edge)
		{
			sum += abs(arr[i.second] - arr[i.first]);
		}

		if (ans > sum)
		{
			ans = sum;
			tmp = arr;
		}
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans << "\n";

	vi v(N);
	for (int i = 0; i < N; i++)
	{
		v[tmp[i]] = i;
	}
	for (auto i : v)
		cout << i << " ";
	cout << "\n";

}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	clock_t begin, end;
	begin = clock();

	int T;

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M;

		for (int i = 0; i < M; i++)
		{
			int from, to;
			cin >> from >> to;
			edge.push_back({ from,to });
		}

		cout << "Case #" << test << "\n";
		Solve();

		edge.clear();
	}

	end = clock();
	cout << "수행시간 : " << end - begin;

	return 0;
}