#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
int person_count;
string temp;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	map<string, int> nohear;
	vector<string> nolook(M);
	vector<string> correct(M);

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		nohear[temp] = 1;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> nolook[i];
	}

	sort(nolook.begin(), nolook.end());

	for (int i = 0; i < M; i++)
	{
		if (nohear[nolook[i]] == 1)
		{
			correct[person_count] = nolook[i];
			person_count++;
		}
	}

	cout << person_count << "\n";
	for (int i = 0; i < person_count; i++)
	{
		cout << correct[i] << "\n";
	}

	return 0;
}