#include <iostream>
using namespace std;

#define siz 1000001
#define MAX 1000000001

int N, M;
int A[siz];
int B[siz];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < M; i++)
		cin >> B[i];

	int *aptr = &A[0];
	int *bptr = &B[0];

	for (int i = 0; i < N + M; i++)
	{
		if (*aptr <= *bptr)
		{
			cout << *aptr;
			aptr++;
			if (aptr == A + N)
				*aptr = MAX;
		}

		else
		{
			cout << *bptr;
			bptr++;
			if (bptr == B + M)
				*bptr = MAX;
		}
		if (i == N + M - 1)
			break;
		cout << " ";
	}

	return 0;
}