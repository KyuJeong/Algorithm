#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string patn;
string file;
string front, back;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	cin >> patn;
	for (int i = 0; i < patn.size(); i++)
	{
		if (patn[i] == '*')
		{
			front = patn.substr(0, i);
			back = patn.substr(i + 1);
			reverse(back.begin(), back.end());
		}

	}

	while (N--)
	{
		cin >> file;
		if (file.size() < patn.size() - 1)
		{
			cout << "NE\n";
			continue;
		}
		int front_idx = file.find(front);

		reverse(file.begin(), file.end());
		int back_idx = file.find(back);
		if (front_idx == 0 && back_idx == 0)
			cout << "DA\n";
		else
			cout << "NE\n";
	}

	return 0;
}