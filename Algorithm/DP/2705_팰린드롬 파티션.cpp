#include <bits/stdc++.h>

using namespace std;

int d[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	d[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 1; j <= i / 2; j++) // ��� ���� �����ϰ� ������ ����� ����� ��
			d[i] += d[j];
		d[i]++;
	}

	int t, x;
	cin >> t;
	while (t--)
	{
		cin >> x;
		cout << d[x] << "\n";
	}

	return 0;
}