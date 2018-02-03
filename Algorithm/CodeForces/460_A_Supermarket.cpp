#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
double a, b;
double avg = 1e9;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		avg = min(avg, a / b);
	}

	printf("%.8f", avg * M);

	return 0;
}