#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int sum;
int temp;

int main()
{
	std::ios::sync_with_stdio(false);

	vector <int> pl;
	vector <int> mn;
	vector <int> zr;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp > 0)
			pl.push_back(temp);
		else if (temp == 0)
			zr.push_back(temp);
		else
			mn.push_back(temp);
	}

	sort(pl.begin(), pl.end());
	sort(zr.begin(), zr.end());
	sort(mn.begin(), mn.end());

	while (pl.size() != 0)
	{
		if (pl.size() > 1)
		{
			if (pl.back() != 1)
			{
				temp = pl.back();
				pl.pop_back();

				if (pl.back() == 1)
					temp += pl.back();
				else
					temp *= pl.back();
			}
			else
				temp = pl.back();
		}
		else
			temp = pl.back();
		pl.pop_back();
		sum += temp;
	}

	while (mn.size() != 0)
	{
		if (mn.size() > 1)
		{
			temp = mn.front();
			mn.erase(mn.begin());
			temp *= mn.front();
		}
		else
		{
			if (zr.size() != 0)
				temp = 0;
			else
				temp = mn.back();
		}
		mn.erase(mn.begin());
		sum += temp;
	}

	cout << sum;

	return 0;
}