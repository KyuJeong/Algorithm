#include <bits/stdc++.h>

using namespace std;

double x[5], y[5];
double grad1, grad2;
double X1, C1, X2, C2;
double X, Y;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 1; i <= 4; i++)
		cin >> x[i] >> y[i];

	double den = (y[4] - y[3]) * (x[2] - x[1]) - (x[4] - x[3]) * (y[2] - y[1]);
	if (den == 0)
	{
		cout << "0";
		return 0;
	}

	double ua = ((x[4] - x[3]) * (y[1] - y[3]) - (y[4] - y[3]) * (x[1] - x[3])) / den;
	double ub = ((x[2] - x[1]) * (y[1] - y[3]) - (y[2] - y[1]) * (x[1] - x[3])) / den;

	if (ua > 0 && ua < 1 && ub > 0 && ub < 1)
		cout << "1";
	else
		cout << "0";

	return 0;
}