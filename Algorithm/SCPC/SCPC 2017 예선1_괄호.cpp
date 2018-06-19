#include <bits/stdc++.h>

using namespace std;

typedef pair <bool, int> pbi;

struct Word
{
	char word;
	int idx;

	Word() {};
	Word(char _word, int _idx)
		: word(_word), idx(_idx) {};
};

struct Close
{
	bool close;
	int idx;

	Close() {};
	Close(bool _close, int _idx)
		: close(_close), idx(_idx) {};
};

int T;
int DP[1000001];
char open[] = "({[";
char close[] = ")}]";

Close isClose(char a)
{
	for (int i = 0; i < 3; i++)
	{
		if (a == close[i])
			return { true, i };
	}
	return { false, 0 };
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 2 4 0 4 8 6

	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		string s;
		stack <Word> st;
		int cnt = 0;
		int ans = 0;
		cin >> s;

		for (int i = 0; i < s.size(); i++)
		{
			Close ch = isClose(s[i]);
			if (st.size() == 0)
			{
				if(!ch.close)
					st.push({ s[i], i });
				cnt = 0;
			}
			else
			{
				if (ch.close)
				{
					Word cur = st.top();
					if (cur.word == open[ch.idx])
					{
						st.pop();
						cnt += 2;
						cnt += DP[cur.idx - 1];

						ans = max(cnt, ans);

						DP[i] = cnt;
					}
					else
					{
						while (!st.empty())
							st.pop();
						cnt = 0;
					}
				}
				else
				{
					cnt = 0;
					st.push({ s[i], i });
				}
			}
		}

		cout << "Case #" << test << "\n";
		cout << ans << "\n";

		memset(DP, 0, sizeof(DP));
	}

	return 0;
}