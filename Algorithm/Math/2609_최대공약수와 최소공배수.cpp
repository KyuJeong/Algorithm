#include <iostream>
using namespace std;

int num1, num2;
int calGCD(int A, int B)
{
	int P;
	while (A != 0 && B != 0)
	{
		if (A >= B)
		{
			P = B;
			A = A % B;
		}
		else
		{
			P = A;
			B = B % A;
		}
	}
	return P;
}
int GCD;
int LCM;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> num1 >> num2;

	int GCD = calGCD(num1, num2);
	cout << GCD << "\n";
	cout << (num1 * num2) / GCD << "\n";

	return 0;
}