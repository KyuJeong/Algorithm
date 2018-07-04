#include <bits/stdc++.h>

using namespace std;

struct Abb
{
	int src, dst;
	string initial;
	Abb() {}
	Abb(int _src, int _dst, string _initial)
		: src(_src), dst(_dst), initial(_initial) {}
};

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	while (getline(cin, s))
	{
		vector <Abb> v; // abbreviaiton sequence(a.s)들의 배열
		s = " " + s + ".";
		bool capital_flag = false; // 이 문자열이 capital 진행중인지
		bool pre_capital = false; // 앞 문자열이 capital인지
		int src = 0; // a.s의 시작 인덱스
		int dst = 0; // a.s의 마지막 인덱스
		string initial; // 첫 글자들의 집합
		char first_upper; // 문자열의 첫 글자
		bool first_flag = false; // 문자열의 첫 문자가 대문자였는지
		bool init_flag = false; // 초기화해야하는지

		for (int i = 1; i < s.size(); i++)
		{
			if (capital_flag) // capital 진행 중일때
			{
				if (s[i] < 'A') // 기호가 나왔을 때
				{
					if (s[i - 1] == ' ' || s[i] != ' ') // 전 문자가 공백이거나 현 문자가 공백이 아닌 기호면
					{
						if (pre_capital)
						{
							dst = i - 1;
							initial += first_upper;
						}
						init_flag = true;
					}

					else if (s[i] == ' ') // 그 기호가 공백이면
					{
						if (pre_capital)
							dst = i - 1;
						pre_capital = true;
						initial += first_upper;
					}

					capital_flag = false;
				}
				else if (s[i] <= 'Z') // 대문자가 다시 나오면
					init_flag = true;
			}
			else // capital 진행 중 아닐 때
			{
				if (s[i] >= 'A' && s[i] <= 'Z') // 대문자가 나왔을 때
				{
					if (s[i - 1] < 'A') // 앞에 기호가 나왔으면
						first_flag = true;
					else
						init_flag = true;
				}
				else if (s[i] >= 'a') // 소문자가 나왔을 때
				{
					if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && first_flag) // 전 문자가 대문자면
					{
						if (!pre_capital)
							src = i - 1;

						capital_flag = true; // capital 진행상태로
						first_upper = s[i - 1]; // 단어의 첫 대문자 저장
					}
					else
						init_flag = true;
				}
				else // 기호가 나왔을 때
					init_flag = true;
			}
			if (init_flag) // 초기화해야할 때
			{
				if (dst != 0)
					v.push_back(Abb{ src,dst,initial });
				pre_capital = false;
				capital_flag = false;
				first_flag = false;
				src = 0;
				dst = 0;
				initial = "";
				init_flag = false;
			}
		}

		int v_cnt = 0; // a.s의 개수

		if (v.size() > v_cnt)
		{
			src = v[v_cnt].src;
			dst = v[v_cnt].dst;
			initial = v[v_cnt].initial;
			v_cnt++;
		}

		for (int i = 1; i < s.size() - 1; i++)
		{
			if (i == src)
				cout << initial << " (";

			cout << s[i];
			if (i == dst)
			{
				cout << ")";
				if (v.size() > v_cnt)
				{
					src = v[v_cnt].src;
					dst = v[v_cnt].dst;
					initial = v[v_cnt].initial;
					v_cnt++;
				}
			}
		}
		cout << "\n";
	}

	return 0;
}