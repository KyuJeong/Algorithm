#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

typedef long long ll;

/*
   (A[i] + ... A[j]) % M == 0
=> (S[j] - S[i-1]) % M == 0
=> S[j] % M - S[i-1] % M ==0
=> S[j] % M == S[i-1] % M
즉, 구간의 나머지가 0이 되려면 S[j] % M == S[i-1] % M이 되어야 한다
cnt[k] = S[i] % M == k인 i의 수라 하고
조합(cnt[k],2) 하면 답

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

	cnt[0]++; // 1개짜리 구간도 세주기 위해
	ll ans = 0;
	for (int i = 0; i < M; i++)
		ans += (cnt[i] * (cnt[i]- 1)) / 2;

	cout << ans;

	return 0;
}