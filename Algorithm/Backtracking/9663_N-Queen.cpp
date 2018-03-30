#include <iostream>
#include <vector>

using namespace std;

typedef vector <bool> vb;

int N;
int ans;

void Solve(int y, int x, vb col, vb inc, vb dec)
{
	if (y > N)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (col[i] || inc[N + y - i] || dec[y + i])
			continue;
		col[i] = inc[N + (y - i)] = dec[y + i] = true;
		Solve(y + 1, i, col, inc, dec);
		col[i] = inc[N + (y - i)] = dec[y + i] = false;
	}

	return;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	vb column(N + 1, false);
	vb incr((N * N) + 1, false);
	vb decr((N * N) + 1, false);

	Solve(1, 1, column, incr, decr);
	cout << ans;

	return 0;
}