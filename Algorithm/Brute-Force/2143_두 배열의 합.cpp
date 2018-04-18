#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int tmp;
vector <int> A;
vector <int> B;
long long ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	
	cin >> N;
	int idx = 0;
	for (int i = 0; i < N; i++) // A의 모든 부 배열을 저장
	{
		cin >> tmp;
		A.push_back(tmp);
		for (int j = 0; j < i; j++)
		{
			A.push_back(A[idx++] + tmp);
		}
	}

	cin >> M;
	idx = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
		for (int j = 0; j < i; j++)
		{
			B.push_back(B[idx++] + tmp);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int L = 0;
	int R = B.size() - 1;

	while (L < A.size() && R >= 0)
	{
		int sum = A[L] + B[R];
		if (sum < T)
			L++;
		else if (sum > T)
			R--;
		else
		{
			int a = A[L];
			int b = B[R];
			long long a_cnt = 0;
			long long b_cnt = 0;
			while (a == A[L])
			{
				a_cnt++;
				L++;
				if (L >= A.size())
					break;
			}
			while (b == B[R])
			{
				b_cnt++;
				R--;
				if (R < 0)
					break;
			}
			ans += a_cnt * b_cnt;
		}
	}

	cout << ans;

	return 0;
}