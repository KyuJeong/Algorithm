#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b, c;

	cin >> a >> b >> c;

	if (a + b == c)
		printf("%d+%d=%d", a, b, c);
	else if (a * b == c)
		printf("%d*%d=%d", a, b, c);
	else if (a - b == c)
		printf("%d-%d=%d", a, b, c); 
	else if (a / b == c)
		printf("%d/%d=%d", a, b, c);
	else if (a == b + c)
		printf("%d=%d+%d", a, b, c);
	else if (a == b * c)
		printf("%d=%d*%d", a, b, c);
	else if (a == b - c)
		printf("%d=%d-%d", a, b, c);
	else
		printf("%d=%d/%d", a, b, c);

	return 0;
}