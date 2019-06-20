/* Not solved */

#include <iostream>
#include <vector>

#define MAX 999999999

using namespace std;

int n, m;
int arr[10000000];
int one_connect[100001];
int fin = 500000;
vector <int> pm;
int dist;
int cnt;

void calPrime()
{
	int idx = 0;

	for (int i = 2; i*i <= fin; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i * 2; j <= fin; j += i)
				arr[j] = 1;
		}
	}

	for (int i = 2; i <= fin; i++)
	{
		if (arr[i] == 0)
			pm.push_back(i);
	}

}

int main()
{
	cin >> n >> m;

	for (int i = 2; i < n; i++)
	{
		one_connect[i] = 2;
	}

	calPrime();

	int sze = pm.size();

	for (int i = 0; i < sze; i++)
	{
		if (2 * (n - 2) < pm[i]) 
		{
			dist = pm[i] - (2 * (n - 2));
			break;
		}
	}

	cout << 2 * (n - 2) + dist << " " << dist << "\n";

	for (int i = 2; i < n; i++)
	{
		printf("1 %d 2\n", i);
		cnt++;
	}
	printf("1 %d %d\n", n, dist);
	cnt++;

	for (int i = 2; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			printf("%d %d %d\n", i, j, MAX);
			cnt++;
			if (cnt == m)
				return 0;
		}
	}



	return 0;
}