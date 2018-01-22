#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int N;
int arr[100001];
int sum;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	priority_queue <int, vector <int>, greater <int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		pq.push(arr[i]);
	}

	while (pq.size() >= 2)
	{
		int tmp = pq.top();
		pq.pop();

		sum = pq.top();
		pq.pop();
		
		sum += tmp;
		pq.push(sum);
		
		ans += sum;
	}

	cout << ans;

	return 0;
}