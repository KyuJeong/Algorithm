#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
	scanf("%d", &N);

	vector <pair <int, int>> location(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &location[i].first, &location[i].second);
	}

	sort(location.begin(), location.end());

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", location[i].first, location[i].second);
	}

	return 0;
}