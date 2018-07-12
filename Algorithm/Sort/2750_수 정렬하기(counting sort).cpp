#include <iostream>

#define MAX 1001 // N�� ũ��
#define INF 2001 // �����ϴ� ���� ū ��

using namespace std;

int A[MAX], B[MAX], cnt[INF], cnt_sum[INF];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		A[i] += 1000; // A[i]�� �ּڰ��� -1000�̹Ƿ� +1000
		cnt[A[i]]++; // ���� ���� Ƚ�� ����
	}

	// ������ ����
	cnt_sum[0] = cnt[0];
	for (int i = 1; i < INF; i++)
		cnt_sum[i] = cnt_sum[i - 1] + cnt[i];

	// �ڿ������� �迭 A�� ��ȸ
	for (int i = N; i >= 1; i--)
		B[cnt_sum[A[i]]--] = A[i];

	for (int i = 1; i <= N; i++)
		cout << B[i] - 1000 << "\n";

	return 0;
}