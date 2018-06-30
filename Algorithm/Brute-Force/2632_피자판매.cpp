#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int s;
int n, m;
vi input_a, input_b;
vi A, B;

void solveA(int sum, int x, int cnt)
{
	if (cnt == n - 1)
		return;
	if (x >= n)
		x %= n;
	A.push_back(sum + input_a[x]);
	solveA(sum + input_a[x], x + 1, cnt + 1);
}

void solveB(int sum, int x, int cnt)
{
	if (cnt == m - 1)
		return;
	if (x >= m)
		x %= m;
	B.push_back(sum + input_b[x]);
	solveB(sum + input_b[x], x + 1, cnt + 1);
}


int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s >> n >> m;
	input_a.resize(n);
	input_b.resize(m);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input_a[i];
		sum += input_a[i];
	}
	A.push_back(sum);
	
	sum = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> input_b[i];
		sum += input_b[i];
	}
	B.push_back(sum);
	
	A.push_back(0);
	for (int i = 0; i < n; i++)
		solveA(0, i, 0);

	B.push_back(0);
	for (int i = 0; i < m; i++)
		solveB(0, i, 0);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ans = 0;
	int L = 0;
	int R = B.size() - 1;
	while (L < A.size() && R >= 0)
	{
		int cnt_a = 0; int cnt_b = 0;
		if (A[L] + B[R] == s)
		{
			int num_a = A[L]; int num_b = B[R];
			while (L < A.size() && A[L] == num_a)
			{
				L++;
				cnt_a++;
			}
			while (R >= 0 && B[R] == num_b)
			{
				R--;
				cnt_b++;
			}
			ans += cnt_a * cnt_b;
		}
		else if (A[L] + B[R] < s)
			L++;
		else
			R--;
	}

	cout << ans;

	return 0;
}