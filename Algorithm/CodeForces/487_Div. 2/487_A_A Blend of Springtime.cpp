#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	cin >> s;

	int idx[6] = { 0 };

	idx[0] = s.find("CBA");
	idx[1] = s.find("ABC");
	idx[2] = s.find("ACB");
	idx[3] = s.find("BAC");
	idx[4] = s.find("BCA");
	idx[5] = s.find("CAB");

	for (int i = 0; i < 6; i++)
	{
		if (idx[i] != -1)
		{
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";

	return 0;
}