#include <bits/stdc++.h>

using namespace std;

int A, B;
string C;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> A >> B >> C;

	int len = C.size();

	int last = (C[len - 1] - '0');

	if (last % 2 == 0)
		cout << A;
	else
		cout << (A ^ B);

	return 0;
}