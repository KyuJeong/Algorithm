#include <iostream>

using namespace std;

int N, M;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	cout << (N - 1) + N * (M - 1);

	return 0;
}