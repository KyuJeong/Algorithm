#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n;
vector <pair <double, double>> v;
double sum;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	double ret = x1 * y2 + x2 * y3 + x3 * y1;
	ret += (-y1 * x2 - y2 * x3 - y3 * x1);
	return ret / 2;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;

	for (int i = 1; i < n - 1; i++)
		sum += ccw(v[0].x, v[0].y, v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);

	cout << fixed;
	cout.precision(1);
	cout << abs(sum);

	return 0;
}