#include <iostream>
#include <string>

using namespace std;

int N;
int arr[5001];
bool visit[5001];
string ans = "NO";

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	
	int cur, nxt_1, nxt_2;
	for (int i = 1; i <= N; i++)
	{
		cur = arr[i];
		nxt_1 = arr[cur];
		nxt_2 = arr[nxt_1];

		if (i == nxt_2)
		{
			ans = "YES";
			break;
		}
	}

	cout << ans;

	return 0;
}