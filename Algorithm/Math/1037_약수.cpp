#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;
int N;
int tmp;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[N - 1];

	return 0;
}