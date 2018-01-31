#include <iostream>
#include <vector>

using namespace std;

#define MAX 4000001

int N;
bool comp_flag[MAX];
vector <int> v;
int idx, sum, ptr, cnt;

void MakePrime()
{
	for (int i = 2; i * i <= N; i++)
	{
		if (!comp_flag[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				comp_flag[j] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (!comp_flag[i])
			v.push_back(i);
	}

	v.push_back(MAX);

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	MakePrime();

	while (v[idx] <= N)
	{
		sum += v[idx];

		while (sum > N)
			sum -= v[ptr++];

		if (sum == N)
			cnt++;

		idx++;
	}

	cout << cnt;

	return 0;
}