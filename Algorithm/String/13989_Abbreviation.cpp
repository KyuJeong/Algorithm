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
		vector <Abb> v; // abbreviaiton sequence(a.s)���� �迭
		s = " " + s + ".";
		bool capital_flag = false; // �� ���ڿ��� capital ����������
		bool pre_capital = false; // �� ���ڿ��� capital����
		int src = 0; // a.s�� ���� �ε���
		int dst = 0; // a.s�� ������ �ε���
		string initial; // ù ���ڵ��� ����
		char first_upper; // ���ڿ��� ù ����
		bool first_flag = false; // ���ڿ��� ù ���ڰ� �빮�ڿ�����
		bool init_flag = false; // �ʱ�ȭ�ؾ��ϴ���

		for (int i = 1; i < s.size(); i++)
		{
			if (capital_flag) // capital ���� ���϶�
			{
				if (s[i] < 'A') // ��ȣ�� ������ ��
				{
					if (s[i - 1] == ' ' || s[i] != ' ') // �� ���ڰ� �����̰ų� �� ���ڰ� ������ �ƴ� ��ȣ��
					{
						if (pre_capital)
						{
							dst = i - 1;
							initial += first_upper;
						}
						init_flag = true;
					}

					else if (s[i] == ' ') // �� ��ȣ�� �����̸�
					{
						if (pre_capital)
							dst = i - 1;
						pre_capital = true;
						initial += first_upper;
					}

					capital_flag = false;
				}
				else if (s[i] <= 'Z') // �빮�ڰ� �ٽ� ������
					init_flag = true;
			}
			else // capital ���� �� �ƴ� ��
			{
				if (s[i] >= 'A' && s[i] <= 'Z') // �빮�ڰ� ������ ��
				{
					if (s[i - 1] < 'A') // �տ� ��ȣ�� ��������
						first_flag = true;
					else
						init_flag = true;
				}
				else if (s[i] >= 'a') // �ҹ��ڰ� ������ ��
				{
					if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && first_flag) // �� ���ڰ� �빮�ڸ�
					{
						if (!pre_capital)
							src = i - 1;

						capital_flag = true; // capital ������·�
						first_upper = s[i - 1]; // �ܾ��� ù �빮�� ����
					}
					else
						init_flag = true;
				}
				else // ��ȣ�� ������ ��
					init_flag = true;
			}
			if (init_flag) // �ʱ�ȭ�ؾ��� ��
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

		int v_cnt = 0; // a.s�� ����

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