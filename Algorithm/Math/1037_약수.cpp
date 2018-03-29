#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <long long> v;
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

	long long ans = v[0] * v[N - 1];

	cout << ans;

	return 0;
}