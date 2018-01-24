#include <iostream>
using namespace std;

int N, M;
int A[50][50];
int B[50][50];
int rev_count;
bool cant_rev;

void rev(int y, int x)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			if (A[i][j] == 0)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
	rev_count++;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &A[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &B[i][j]);
		}
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (A[i][j] != B[i][j])
				rev(i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
				cant_rev = true;
		}
	}

	if (cant_rev)
		cout << "-1";
	else
		cout << rev_count;

	return 0;
}