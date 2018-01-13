#include <iostream>

using namespace std;

int N;
int DP[31];	// 대칭 고려 안했을 때 전체 타일의 개수
int ans_DP[31];	// 대칭인 타일을 뺐을 때 전체 타일의 개수
int tmp;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[1] = 1;
	DP[2] = 3;
	ans_DP[1] = 1;
	ans_DP[2] = 3;
	for (int i = 3; i <= N; i++)
	{
		DP[i] = DP[i - 1] + (DP[i - 2] * 2);
		if (i % 2 == 0)
			tmp = DP[(i - 2) / 2] * 2 + DP[i / 2];
		else
			tmp = DP[(i - 1) / 2];
		ans_DP[i] = (DP[i] + tmp) / 2; 	// (대칭 * 2 + 비대칭) / 2 == 대칭된 걸 뺀 타일의 개수
	}

	cout << ans_DP[N];

	return 0;
}