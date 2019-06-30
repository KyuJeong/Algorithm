#include <bits/stdc++.h>

using namespace std;

int n, k;
char arr[4194306];

void hanoi(int num, char pre, char nxt)
{
	if (num == 0) return;
	char tmp = '6' + '0' + '0' - pre - nxt;
	hanoi(num - 1, pre, tmp);
	arr[k++] = pre;
	arr[k++] = ' ';
	arr[k++] = nxt;
	arr[k++] = '\n';
	hanoi(num - 1, tmp, nxt);
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	hanoi(n, '1', '3');

	cout << k / 4 << "\n";
	arr[k] = NULL;
	cout << arr;

	return 0;
}