#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define MOD 1000000007

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

double n, m;
double A[1001];
double B[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (A[i] == 1)
		{
			cout << "-1";
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
		if (B[i] == 1)
		{
			cout << "-1";
			return 0;
		}
	}

	double cur = m;
	double t = cur / (B[0] - 1);
	cur += t;

	for (int i = n - 1; i > 0; i--)
	{
		t = cur / (A[i] - 1);
		cur += t;
		t = cur / (B[i] - 1);
		cur += t;
	}
	t = cur / (A[0] - 1);
	cur += t;
	
	cout.precision(12);
	cout << cur - m;

	return 0;
}
