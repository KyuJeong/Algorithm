#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	cin >> str;

	if (N == 1)
	{
		if (str[0] == '?')
			cout << "Yes";
		else
			cout << "No";
		return 0;
	}

	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[i - 1] && str[i] != '?')
		{
			cout << "No";
			return 0;
		}
	}

	if (str[0] == '?')
	{
		cout << "Yes";
		return 0;
	}

	if (str[str.size() - 1] == '?')
	{
		cout << "Yes";
		return 0;
	}

	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] == '?')
		{
			if (str[i - 1] == '?' || str[i + 1] == '?')
			{
				cout << "Yes";
				return 0;
			}
			if (str[i - 1] == str[i + 1])
			{
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";

	return 0;
}