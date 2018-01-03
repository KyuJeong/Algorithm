#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int min = N;
	int max = M;
	if (N > M)
	{
		min = M;
		max = N;
	}
	int size = 1;

	vector<string> num;
	string a;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		num.push_back(a);
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < max; j++)
		{
			for (int k = 1; k < min; k++)
			{
				if ((j + k) < M && (i + k) < N)
				{
					if (num[i].at(j) == num[i].at(j + k))
					{
						if (num[i].at(j) == num[i + k].at(j) && num[i + k].at(j) == num[i + k].at(j + k))
						{
							if (((k + 1) * (k + 1)) >= size)
								size = (k + 1) * (k + 1);
						}
					}
				}
			}
		}
	}

	cout << size << endl;


	return 0;
}