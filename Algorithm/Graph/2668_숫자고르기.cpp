#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int num[101];
vector <int> ans;

int call_idx[101];
int cycle_cnt[101];

void DFS(int idx)
{
	stack <int> stk;
	int cur = idx;

	int cnt = 1;

	while (1)
	{
		stk.push(cur);
		cur = num[cur];

		if (call_idx[cur] == idx)
		{
			cnt = cnt - cycle_cnt[cur];

			for (int i = 0; i < cnt; i++)
			{
				ans.push_back(stk.top());
				stk.pop();
			}

			return;
		}
		else if (call_idx[cur] != 0)
			return;

		cycle_cnt[cur] = cnt;
		call_idx[cur] = idx;
		cnt++;
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		if (i == num[i])
		{
			ans.push_back(i);
			call_idx[i] = -1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (call_idx[i] == 0)
			DFS(i);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}