#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int my[4] = { 1,1,0,0 };
int mx[4] = { 1,0,1,0 };
int cnt;
int ans;

void Recursion(int row, int col, int side)
{
	if (side == 2)
	{
		if (row == r && col == c)
		{
			cout << cnt;
			exit(0);
		}
		else
			cnt++;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nxt_side = side / 2;
			int nxt_row = row - (my[i] * nxt_side);
			int nxt_col = col - (mx[i] * nxt_side);

			if (nxt_row < r || nxt_col < c)
				cnt += (nxt_side * nxt_side);
			else
				Recursion(nxt_row, nxt_col, nxt_side);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> r >> c;

	Recursion(pow(2, N) - 1, pow(2, N) - 1, pow(2, N));

	return 0;
}