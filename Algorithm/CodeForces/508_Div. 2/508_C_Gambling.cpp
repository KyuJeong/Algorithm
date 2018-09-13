#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

vector <ll> A;
vector <ll> B;
ll a, b;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	A.resize(n);
	B.resize(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int a_ptr = n - 1;
	int b_ptr = n - 1;

	for (int i = 0; i < n; i++)
	{
		if (a_ptr < 0) b_ptr--;
		else if (b_ptr < 0) a += A[a_ptr--];
		else
		{
			if (A[a_ptr] < B[b_ptr]) b_ptr--;
			else a += A[a_ptr--];
		}

		if (b_ptr < 0) a_ptr--;
		else if (a_ptr < 0) b += B[b_ptr--];
		else
		{
			if (B[b_ptr] < A[a_ptr]) a_ptr--;
			else b += B[b_ptr--];
		}
	}

	cout << a - b;

	return 0;
}