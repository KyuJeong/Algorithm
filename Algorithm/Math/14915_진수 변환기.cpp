#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;

	if (M == 0)
	{
		cout << "0";
		return 0;
	}

	stack <int> s;

	while (M > 0)
	{
		s.push(M % N);
		M /= N;
	}

	while (!s.empty())
	{
		int num = s.top();
		s.pop();

		if (num < 10)
			cout << num;
		else
			cout << (char) (num % 10 + 'A');
	}

	return 0;
}