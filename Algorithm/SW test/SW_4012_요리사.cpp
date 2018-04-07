#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T;
int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int N;
		cin >> N;
		int S[17][17];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> S[i][j];
			}
		}

		vector <int> arr;

		for (int i = 0; i < N / 2; i++)
		{
			arr.push_back(0);
		}

		for (int i = N / 2; i < N; i++)
		{
			arr.push_back(1);
		}

		vector <int> arr2;

		for (int i = 0; i < 2; i++)
		{
			arr2.push_back(0);
		}

		for (int i = 2; i < N / 2; i++)
		{
			arr2.push_back(1);
		}

		int _min = 1e9;

		do
		{
			vector <int> grp1;
			vector <int> grp2;

			for (int i = 0; i < N; i++)
			{
				if (arr[i] == 0)
					grp1.push_back(i);
				else
					grp2.push_back(i);
			}

			int A = 0;

			do
			{
				int idx = 0;
				int n[2];

				for (int i = 0; i < N / 2; i++)
				{
					if (arr2[i] == 0)
					{
						n[idx] = grp1[i];
						idx++;
					}
				}
				A = A + S[n[0]][n[1]] + S[n[1]][n[0]];

			} while (next_permutation(arr2.begin(), arr2.end()));
			
			int B = 0;

			do
			{
				int idx = 0;
				int n[2];

				for (int i = 0; i < N / 2; i++)
				{
					if (arr2[i] == 0)
					{
						n[idx] = grp2[i];
						idx++;
					}
				}
				B = B + S[n[0]][n[1]] + S[n[1]][n[0]];

			} while (next_permutation(arr2.begin(), arr2.end()));

			int sub = abs(A - B);
			_min = min(_min, sub);

		} while (next_permutation(arr.begin(), arr.end()));

		int ans = _min;
		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}