#include <iostream>
#include <string>

using namespace std;

int N;
string s[50];
int alp[50];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}

	int size = s[0].size();

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (s[0][j] == s[i][j])
				alp[j]++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (alp[i] == N - 1)
			cout << s[0][i];
		else
			cout << "?";
	}

	return 0;
}