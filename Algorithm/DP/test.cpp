#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int arr[] = { 10,20,30,40,50 };

	int *ptr = arr;

	int v = *ptr++;

	cout << v;

	int a = 10;

	int b = a++;

	cout << b;

	return 0;
}