#include <iostream>
using namespace std;

int main()
{
	int n;
	int input;
	int sum = 0;
	int max = -1000;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (sum < 0)
			sum = input;
		else
			sum += input;
		if (max < sum)
			max = sum;
	}
	cout << max;

	return 0;
}