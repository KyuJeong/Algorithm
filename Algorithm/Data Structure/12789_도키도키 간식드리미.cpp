#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	int tmp;
	queue <int> q;
	stack <int> st;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}

	int idx = 1;

	while (!q.empty() || !st.empty())
	{
		if (!st.empty())
		{
			int st_cur = st.top();
			if (st_cur == idx)
			{
				st.pop();
				idx++;
				continue;
			}
			else
			{
				if (q.empty())
				{
					cout << "Sad";
					return 0;
				}
			}
		}

		int q_cur = q.front();
		q.pop();
		if (q_cur == idx)
			idx++;
		else
			st.push(q_cur);
	}

	cout << "Nice";

	return 0;
}