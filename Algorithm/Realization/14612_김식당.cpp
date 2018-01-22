#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;

int N, M;
string ord;
int tbl, t;
vector <pair <int, int>> v;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	while (N--)
	{
		cin >> ord;
		if (ord == "order")
		{
			cin >> tbl >> t;
			v.push_back(pii(t, tbl));
		}
		else if (ord == "sort")
		{
			sort(v.begin(), v.end());
		}
		else
		{
			cin >> tbl;
			for (auto it = v.begin(); it != v.end(); it++)
			{
				if (it->second == tbl)
				{
					v.erase(it);
					break;
				}
			}
		}
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cout << it->second << " ";
		}

		if (v.size() == 0)
			cout << "sleep";

		cout << "\n";
	}

	return 0;
}