#include <iostream>
#include <cmath>

using namespace std;

#define pi 3.14159265358979323846

int R;

int main()
{
	cin.tie(NULL);

	cin >> R;

	double ucl = R * R * pi;
	double tax = R * R * 2;

	printf("%.6f\n", ucl);
	printf("%.6f\n", tax);

	return 0;
}