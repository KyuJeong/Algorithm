#include <iostream>
#include <vector>
using namespace std;

int T, N;
int start_index;
int cur_index;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N;
		vector <int> V(N + 1);
		bool check[1001] = { 0 };
		int cycle_count = 0;

		for (int i = 1; i <= N; i++)
		{
			cin >> V[i];
		}

		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				start_index = i;
				check[i] = true;
				cur_index = V[i];
				cycle_count++;
			}

			while (cur_index != start_index)
			{
				check[cur_index] = true;
				cur_index = V[cur_index];
			}
		}

		cout << cycle_count << "\n";
	}

	return 0;
}