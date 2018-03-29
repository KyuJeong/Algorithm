#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;

	cin >> N;

	int ans = 0;

	if (N % 400 == 0)
		ans = 1;

	else if ((N % 4) == 0 && (N % 100) != 0)
		ans = 1;

	cout << ans;

	return 0;
}