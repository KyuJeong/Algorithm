#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int card[500000];
int input;
int ans;

bool b_search(int num)
{
	int left = 0;
	int right = N - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (card[mid] == num)
		{
			ans = mid;
			return true;
		}

		else if (card[mid] > num)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
	}

	sort(card, card + N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &input);
		if (b_search(input))
			printf("%d ", 1);
		else
			printf("%d ", 0);
	}

	return 0;
}