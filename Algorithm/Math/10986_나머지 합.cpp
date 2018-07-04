#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

typedef long long ll;

/*
   (A[i] + ... A[j]) % M == 0
=> (S[j] - S[i-1]) % M == 0
=> S[j] % M - S[i-1] % M ==0
=> S[j] % M == S[i-1] % M
��, ������ �������� 0�� �Ƿ��� S[j] % M == S[i-1] % M�� �Ǿ�� �Ѵ�
cnt[k] = S[i] % M == k�� i�� ���� �ϰ�
����(cnt[k],2) �ϸ� ��

*/

int N, M;
ll sum;
ll cnt[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	int t;
	for (int i = 1; i <= N; i++)
	{
		cin >> t;
		sum += t;
		cnt[sum % M]++;
	}

	cnt[0]++; // 1��¥�� ������ ���ֱ� ����
	ll ans = 0;
	for (int i = 0; i < M; i++)
		ans += (cnt[i] * (cnt[i]- 1)) / 2;

	cout << ans;

	return 0;
}