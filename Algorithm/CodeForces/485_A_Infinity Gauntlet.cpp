#include <bits/stdc++.h>

using namespace std;

string gem[6] = { "Power","Time","Space","Soul","Reality","Mind" };
bool color[6] = { false };

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	string s;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "purple")
			color[0] = true;
		else if (s == "green")
			color[1] = true;
		else if (s == "blue")
			color[2] = true;
		else if (s == "orange")
			color[3] = true;
		else if (s == "red")
			color[4] = true;
		else
			color[5] = true;
	}

	cout << 6 - N << "\n";

	for (int i = 0; i < 6; i++)
	{
		if (!color[i])
			cout << gem[i] << "\n";
	}

	return 0;
}