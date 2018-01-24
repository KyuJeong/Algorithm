#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int team_count;
int remain;
int minus_team;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	team_count = min(N / 2, M);
	remain = N - (team_count * 2) + M - team_count;

	if (K <= remain)
	{
		cout << team_count;
		return 0;
	}
	K -= remain;

	minus_team = (K - 1) / 3 + 1;

	cout << team_count - minus_team;

	return 0;
}