#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Member 
{
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(const Member a, const Member b)
{
	if (a.korean == b.korean)
	{
		if (a.english == b.english)
		{
			if (a.math == b.math)
			{
				return a.name < b.name;
			}
			else
			{
				return a.math > b.math;
			}
		}
		else
		{
			return a.english < b.english;
		}
	}
	else
	{
		return a.korean > b.korean;
	}
}

int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	vector <Member> member(N);

	for (int i = 0; i < N; i++)
	{
		cin >> member[i].name >> member[i].korean >> member[i].english >> member[i].math;
	}

	sort(member.begin(), member.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << member[i].name << "\n";
	}

	return 0;
}