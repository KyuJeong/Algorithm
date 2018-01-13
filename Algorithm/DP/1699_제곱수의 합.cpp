#include <iostream>
using namespace std;

int DP[100001];
int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 100000; i++)
	{
		DP[i] = 100001;
	}

	for (int i = 1; i <= 317; i++)
	{
		DP[i * i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (DP[i] > DP[i - j * j] + 1) // N���� �������� �ϳ��� ���鼭 �˻�
			{
				DP[i] = DP[i - j * j] + 1; // �ּڰ� ���
			}
		}
	}

	cout << DP[N];

	return 0;
}