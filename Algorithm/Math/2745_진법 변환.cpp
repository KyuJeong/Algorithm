#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string B;
int N;
int num_size;
int coverted_num;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> B;
	cin >> N;

	num_size = B.size();

	for (int i = 0; i < num_size; i++)
	{
		if (B[i] <= 57)
			coverted_num += (B[i] - '0') * pow(N, num_size - 1 - i);
		else
			coverted_num += (B[i] - 55) * pow(N, num_size - 1 - i);
	}

	cout << coverted_num;

	return 0;
}