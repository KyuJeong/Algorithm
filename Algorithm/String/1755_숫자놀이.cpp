#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair <string, int> psi;

int M, N;
vector <psi> v;
string alp[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten" };

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		if (i < 10)
			v.push_back({ alp[i], i });
		else
			v.push_back({ alp[i / 10] + alp[i % 10], i });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " ";
		if (i % 10 == 9)
			cout << "\n";
	}


	return 0;
}