#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

vi palin;
int len;
int N;

void MakePalindrome()
{
	for (int i = 1; i <= 10000; i++)
	{
		string s = to_string(i);

		string r = s;
		reverse(r.begin(), r.end());
		if (r == s)
			palin.push_back(stoi(s));
	}
}

bool Solve()
{
	for (int i = 0; i < len; i++)
	{
		if (N == palin[i])
		{
			cout << "1 " << N << "\n";
			return true;
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		int a = palin[i];
		for (int j = i + 1; j < len; j++)
		{
			if (a + palin[j] == N)
			{
				cout << "2 " << a << " " << palin[j] << "\n";
				return true;
			}
		}
	}

	for (int i = 0; i < len - 2; i++)
	{
		int a = palin[i];
		for (int j = i + 1; j < len - 1; j++)
		{
			int b = a + palin[j];
			for (int k = j + 1; k < len; k++)
			{
				if (b + palin[k] == N)
				{
					cout << "3 " << a << " " << palin[j] << " " << palin[k] << "\n";
					return true;
				}
			}
			
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	MakePalindrome();
	len = palin.size();

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N;

		cout << "Case #" << test << "\n";
		bool flag = Solve();
		if (!flag)
			cout << "0\n";
	}

	return 0;
}