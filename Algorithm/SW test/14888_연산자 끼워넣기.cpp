#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[12];
vector <int> v;
int _max = -1000000000;
int _min = 1000000000;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++)
	{
		int tmp;
		cin >> tmp;
		for(int j=0; j<tmp; j++)
			v.push_back(i);
	}

	do 
	{
		int sum = A[0];
		for (int i = 0; i < N - 1; i++)
		{
			switch (v[i])
			{
			case 0:
				sum += A[i + 1];
				break;
			case 1:
				sum -= A[i + 1];
				break;
			case 2:
				sum *= A[i + 1];
				break;
			case 3:
				sum /= A[i + 1];
				break;
			}
		}
		_max = max(_max, sum);
		_min = min(_min, sum);
	} while (next_permutation(v.begin(), v.end()));


	cout << _max << "\n" << _min << "\n";

	return 0;
}