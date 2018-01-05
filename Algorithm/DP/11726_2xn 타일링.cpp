#include <iostream>
using namespace std;

int DP[1000];

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	DP[0] = 1; // n = 1일떄
	DP[1] = 2; // n = 2일때

	for (int i = 2; i < n; i++)	// 계산식
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007; // 오버플로우를 예방하기 위해서 계산할때마다 나눠줌
	}

	cout << DP[n - 1];

	return 0;
}

