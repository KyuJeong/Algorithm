#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];

bool BinarySearch(int num)
{
	int lft = 0;
	int rht = N - 1;

	while (lft <= rht)
	{
		int mid = (lft + rht) / 2;
		if (num == A[mid])
			return true;

		if (num < A[mid])
			rht = mid - 1;
		else
			lft = mid + 1;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	int num;
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (BinarySearch(num))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}