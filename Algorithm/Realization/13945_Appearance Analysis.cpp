#include <bits/stdc++.h>

using namespace std;

struct Window
{
	int row;
	int col;
	int paint;

	Window() {};
	Window(int _row, int _col, int _paint) :
		row(_row), col(_col), paint(_paint) {};
};

int r, c;
char G[112][112];
int garo, sero;
vector <Window> window;
bool check[10000];

void calSize()
{
	for (int i = 1; i <= r; i++)
	{
		if (G[i][1] == '#')
		{
			sero = i - 1;
			break;
		}
	}
	for (int i = 1; i <= c; i++)
	{
		if (G[1][i] == '#')
		{
			garo = i - 1;
			break;
		}
	}
}

void divide()
{
	for (int i = 1; i < r; i += (sero + 1))
	{
		for (int j = 1; j < c; j += (garo + 1))
		{
			int cnt = 0;
			for (int k = i; k <= i + sero; k++)
			{
				for (int l = j; l <= j + garo; l++)
				{
					if (G[k][l] == '+')
						cnt++;
				}
			}
			window.push_back({ i,j, cnt });
		}
	}
}

void rotate90(Window w)
{
	char c[100][100];
	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			c[i][j] = G[w.row + i][w.col + j];
		}
	}

	char n[100][100];
	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			n[i][j] = c[j][garo - 1 - i];
		}
	}

	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			G[w.row + i][w.col + j] = n[i][j];
		}
	}
}

void rotate180(Window w)
{
	int sr = w.row + (w.row + sero) - 1;
	int sc = w.col + (w.col + garo) - 1;

	int cnt = 0;
	int fin = (garo * sero) / 2;

	for (int i = w.row; i < w.row + sero; i++)
	{
		for (int j = w.col; j < w.col + garo; j++)
		{
			swap(G[i][j], G[sr - i][sc - j]);
			if (++cnt == fin)
				return;
		}
	}
}

bool compare(Window w1, Window w2)
{
	if (w1.paint != w2.paint)
		return false;

	int dr = w2.row - w1.row;
	int dc = w2.col - w1.col;

	bool ret = true;

	for (int i = w1.row; i < w1.row + sero; i++)
	{
		for (int j = w1.col; j < w1.col + garo; j++)
		{
			if (G[i][j] != G[i + dr][j + dc])
			{
				return false;
			}
		}
	}

	return true;
	rotate180(w1);
	if (garo == sero)
		rotate90(w1);

}

void solve(int x)
{
	int size = window.size();
	for (int j = x + 1; j < size; j++)
	{
		if (check[j])
			continue;

		bool chk = compare(window[x], window[j]);
		if (chk)
			check[j] = true;
	}

}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> G[i];
	}

	calSize();
	divide();

	int ans = 0;
	int size = window.size();
	for (int i = 0; i < size; i++)
	{
		if (check[i])
			continue;
		ans++;

		solve(i);
		rotate180(window[i]);
		solve(i);

		if (garo == sero)
		{
			rotate90(window[i]);
			solve(i);
			rotate180(window[i]);
			solve(i);
		}
	}

	cout << ans;

	return 0;
}