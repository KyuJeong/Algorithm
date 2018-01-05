#include <iostream>
using namespace std;

int DP[1000];

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	DP[0] = 1; // n = 1�ϋ�
	DP[1] = 2; // n = 2�϶�

	for (int i = 2; i < n; i++)	// ����
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007; // �����÷ο츦 �����ϱ� ���ؼ� ����Ҷ����� ������
	}

	cout << DP[n - 1];

	return 0;
}

