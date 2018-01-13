#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	string num1, num2;

	for (int i = 0; i < T; i++)
	{
		cin >> num1;
		cin >> num2;

		int distance = 0;
		for (int j = 0; j < num1.length(); j++)
		{
			if (num1.at(j) != num2.at(j))
				distance++;
		}
		printf("Hamming distance is %d.\n", distance);
	}


	return 0;
}