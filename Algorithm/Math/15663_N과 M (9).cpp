#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <bool> vb;

int N, M;
vb check;
vi arr;
bool repeat_flag[9][10001]; // [N][M] = 카운트가 N일 때 M을 사용했는지 여부

void Solve(int cnt, int cur, vi v)
{
	if (cnt > M)
	{
		for (int i = 0; i < M; i++)
		{
			int idx = v[i];
			cout << arr[idx] << " ";
		}

		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		int idx = arr[i];
		if (!check[i] && !repeat_flag[cnt][idx])
		{
			check[i] = true;
			repeat_flag[cnt][idx] = true;
			v.push_back(i);
			
			Solve(cnt + 1, i, v);
			
			check[i] = false;
			v.pop_back();
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int idx = arr[i];
		repeat_flag[cnt][idx] = false;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	arr.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	check.resize(N + 1);

	vi v;

	Solve(1, 0, v);

	return 0;
}