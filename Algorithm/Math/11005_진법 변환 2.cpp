#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, B;
string convert;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> B;

	while (N != 0)
	{
		if (N % B < 10)
			convert += to_string(N % B);
		else
			convert += (N % B) + 55;
		N /= B;
	}

	reverse(convert.begin(), convert.end());

	cout << convert;

	return 0;
}