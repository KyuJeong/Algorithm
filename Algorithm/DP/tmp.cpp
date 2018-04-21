#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solution(string s)
{
	int answer = 0;

	int S = s.size();
	string s2 = "";
	for (int i = 0; i < S; i++)
	{
		s2 += '#';
		s2 += s[i];
	}

	s2 += '#';

	int A[5000] = { 0 };

	S = s2.size();
	int R = 0;
	int p = 0;
	for (int i = 0; i < S; i++)
	{
		if (i <= R)
		{
			int m = 2 * p - i;
			A[i] = min(R - i, A[m]);
		}

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < S && (s2[i - A[i] - 1] == s2[i + A[i] + 1]))
		{
			A[i]++;
		}

		if (i + A[i] > R)
		{
			p = i;
			R = i + A[i];
		}
		answer = max(answer, A[i]);
	}

	return answer;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int ans = solution(s);

	cout << ans;
}