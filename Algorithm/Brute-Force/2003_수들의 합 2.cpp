#include <iostream>

using namespace std;

int N , M;
int tmp;
int ptr = 1;
int arr[10001];
int sum;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		sum += tmp;
		arr[i] = tmp;

		while (sum > M)	// 합이 M보다 크면 앞에서부터 뺌
			sum -= arr[ptr++];

		if (sum == M)
			ans++;
	}

	cout << ans;

	return 0;
}