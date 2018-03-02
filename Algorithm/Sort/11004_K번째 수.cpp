#include <iostream>
#include <algorithm>
using namespace std;

long long int num[5000000];
int N, K;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	sort(num, num + N);

	cout << num[K - 1];

	return 0;
}