#include <iostream>

using namespace std;

int N;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	int ans = N / 2 + 1;

	cout << ans;

	return 0;
}