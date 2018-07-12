#include <iostream>

#define MAX 1001 // N의 크기
#define INF 2001 // 등장하는 가장 큰 수

using namespace std;

int A[MAX], B[MAX], cnt[INF], cnt_sum[INF];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		A[i] += 1000; // A[i]의 최솟값이 -1000이므로 +1000
		cnt[A[i]]++; // 숫자 등장 횟수 세기
	}

	// 누적합 세기
	cnt_sum[0] = cnt[0];
	for (int i = 1; i < INF; i++)
		cnt_sum[i] = cnt_sum[i - 1] + cnt[i];

	// 뒤에서부터 배열 A를 순회
	for (int i = N; i >= 1; i--)
		B[cnt_sum[A[i]]--] = A[i];

	for (int i = 1; i <= N; i++)
		cout << B[i] - 1000 << "\n";

	return 0;
}