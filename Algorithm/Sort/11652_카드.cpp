#include <iostream>
#include <algorithm>
using namespace std;

long long int card[1000001][2];
int N;
long long int num;
int ptr;
int maxCount;
long long int maxNum;
bool isFound;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	ptr = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		isFound = false;
		for (int j = 1; j < ptr; j++)
		{
			if (num == card[j][0])
			{
				card[j][1]++;
				isFound = true;
				break;
			}
		}
		if (!isFound)
		{
			card[ptr][0] = num;
			card[ptr][1]++;
			ptr++;
		}
	}

	for (int i = 1; i <= ptr; i++)
	{
		if (card[i][1] > maxCount)
		{
			maxCount = card[i][1];
			maxNum = card[i][0];
		}
		else if (card[i][1] == maxCount)
		{
			maxNum = min(card[i][0], maxNum);
		}

	}

	cout << maxNum;

	return 0;
}