#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;

vector <pair <int, string>> v;
string tmp;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].second;
		v[i].first = v[i].second.size();
	}

	sort(v.begin(), v.end());

	cout << v[0].second << "\n";

	for (int i = 1; i < N; i++)
	{
		if (v[i] != v[i - 1])
			cout << v[i].second << "\n";
	}
	return 0;
}