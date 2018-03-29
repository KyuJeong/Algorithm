#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[50];
int B[50];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A, A + N);

	sort(B, B + N);

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		ans += A[i] * B[N - i - 1];
	}

	cout << ans;


	return 0;
}