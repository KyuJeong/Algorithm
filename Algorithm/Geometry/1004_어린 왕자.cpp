#include <iostream>
#include <cmath>

using namespace std;

typedef pair <int, int> pii;

int T;

bool Position(pii point, int x, int y, int r)
{
	int p1 = point.first;
	int p2 = point.second;

	double dist = ((p2 - y) * (p2 - y) + ((p1 - x) * (p1 - x)));
	dist = sqrt(dist);

	if (dist < r)
		return true;
	else
		return false;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		pii src, dst;
		int n;
		int t1, t2, t3;
		int ans = 0;

		cin >> src.first >> src.second >> dst.first >> dst.second;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> t1 >> t2 >> t3;
			if (Position(src, t1, t2, t3) ^ Position(dst, t1, t2, t3))
				ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}