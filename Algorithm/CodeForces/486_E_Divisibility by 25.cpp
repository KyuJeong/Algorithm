#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

vector <char> v;
int idx[10];
int zero[2];
int move_count[10][10];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	char ch;

	while (cin >> ch)
	{
		v.push_back(ch);
	}

	memset(idx, -1, sizeof(idx));
	zero[0] = -1; zero[1] = -1;

	int len = v.size() - 1;
	if (len == 0)
	{
		cout << "-1";
		return 0;
	}
	for (int i = 0; i <= len; i++)
	{
		if (v[i] == '0')
		{
			zero[0] = zero[1];
			zero[1] = i;
			idx[0] = i;
		}
		else if (v[i] == '2')
			idx[2] = i;
		else if (v[i] == '5')
			idx[5] = i;
		else if (v[i] == '7')
			idx[7] = i;
	}

	move_count[0][0] = move_count[2][5] = move_count[5][0] = move_count[7][5] = INF;

	if (zero[0] != -1) // 0이 두개이상이면
	{
		move_count[0][0] = len - zero[1] + len - 1 - zero[0];
	}

	if (idx[5] == -1) // 5가 없을 때
	{
		if (zero[0] == -1)
			cout << "-1";
		else
			cout << move_count[0][0];
		return 0;
	}
	else // 5가 있을 때
	{
		if (idx[0] == -1 && idx[2] == -1 && idx[7] == -1)
		{
			cout << "-1";
			return 0;
		}
		if (idx[0] == -1) // 0이 없을 때
		{
			if (idx[2] != -1)
			{
				if (idx[2] > idx[5]) // 2가 더 뒤에 있을 때
					move_count[2][5] = len - idx[2] + len - idx[5];
				else
					move_count[2][5] = len - 1 - idx[2] + len - idx[5];
			}
			if (idx[7] != -1)
			{
				if (idx[7] > idx[5]) // 2가 더 뒤에 있을 때
					move_count[7][5] = len - idx[7] + len - idx[5];
				else
					move_count[7][5] = len - 1 - idx[7] + len - idx[5];
			}
			cout << min(move_count[2][5], move_count[7][5]);
			return 0;
		}
		else // 0이 있을 때
		{
			if (idx[2] != -1)
			{ // 맨 앞에 5가 있고 바로 뒤에 0이 나올 때
				if (v[1] == '0' && idx[5] == 0)
				{
					int cnt = 0;
					for (int i = 1; i < v.size(); i++)
					{
						if (v[i] != '0')
							break;
						cnt++;
					}
					move_count[2][5] = len + cnt;
				}
				else
				{
					if (idx[2] > idx[0])
					{
						if (idx[2] > idx[5]) // 2가 더 뒤에 있을 때
							move_count[2][5] = len - idx[2] + len - idx[5];
						else
							move_count[2][5] = len - 1 - idx[2] + len - idx[5];
					}
				}
			}
			if (idx[7] != -1)
			{ // 맨 앞에 5가 있고 바로 뒤에 0이 나올 때
				if (v[1] == '0' && idx[5] == 0) 
				{
					int cnt = 0;
					for (int i = 1; i < v.size(); i++)
					{
						if (v[i] != '0')
							break;
						cnt++;
					}
					move_count[7][5] = len + cnt;
				}
				else
				{
					if (idx[7] > idx[0])
					{
						if (idx[7] > idx[5]) // 7이 더 뒤에 있을 때
							move_count[7][5] = len - idx[7] + len - idx[5];
						else
							move_count[7][5] = len - 1 - idx[7] + len - idx[5];
					}
				}
			}
			if (v[1] == '0' && idx[5] == 0)
			{
				if (zero[0] == -1)
				{
					move_count[5][0] = len - 1 - idx[0] + len - idx[5];
				}
			}
			else
			{
				if (idx[5] > idx[0]) // 5가 더 뒤에 있을 때
					move_count[5][0] = len - idx[5] + len - idx[0];
				else
					move_count[5][0] = len - 1 - idx[5] + len - idx[0];
			}

			int _min = min({ move_count[0][0] , move_count[2][5], move_count[5][0], move_count[7][5] });
			cout << _min;
		}
	}


	return 0;
}