#include <iostream>

using namespace std;

int N, M;
bool comp_flag[10001];
int _min;
int sum;

void MakePrime()
{
	comp_flag[1] = true;

	for (int i = 2; i * i <= M; i++)
	{
		if (!comp_flag[i])
		{
			for (int j = i * i; j <= M; j += i)
			{
				comp_flag[j] = true;
			}
		}
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	MakePrime();

	for (int i = M; i >= N; i--)
	{
		if (!comp_flag[i])
		{
			sum += i;
			_min = i;
		}
	}

	if (sum == 0)
		cout << "-1";
	else
		cout << sum << "\n" << _min;

	return 0;
}