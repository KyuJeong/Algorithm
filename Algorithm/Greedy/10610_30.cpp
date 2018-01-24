#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string N;
int sum;
bool has_zero;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	for (char c : N)
	{
		sum += c - '0';
		if (c == '0')
			has_zero = true;
	}

	if (!has_zero || sum % 3 != 0)
	{
		cout << "-1";
		return 0;
	}

	sort(N.begin(), N.end());
	reverse(N.begin(), N.end());

	cout << N;

	return 0;
}