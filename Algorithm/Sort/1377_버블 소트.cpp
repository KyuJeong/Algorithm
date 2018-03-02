#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair <int, int>> A(N + 1);
	int countChange = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin() + 1, A.end());

	for (int i = 1; i <= N; i++)
	{
		countChange = max(countChange, A[i].second - i);
	}

	cout << countChange + 1;

	return 0;
}