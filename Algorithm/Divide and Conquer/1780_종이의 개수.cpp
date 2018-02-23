#include <iostream>
using namespace std;

int N;
int room[2188][2188];
int moveY[] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
int moveX[] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
int count_paper[3];

int paper(int startY, int startX, int siz)
{
	int save_value[9];
	bool is_same = true;

	for (int i = 0; i < 9; i++)
	{
		if (siz == 1)
			return room[startY][startX];
		int ny = startY + (moveY[i] * siz / 3);
		int nx = startX + (moveX[i] * siz / 3);
		save_value[i] = paper(ny, nx, siz / 3);

	}

	for (int i = 1; i < 9; i++)
	{
		if (save_value[i] != -2 && (save_value[i - 1] != save_value[i]))
			is_same = false;
	}

	if (is_same)
	{
		return save_value[0];
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (save_value[i] == -1)
				count_paper[0]++;
			else if (save_value[i] == 0)
				count_paper[1]++;
			else if (save_value[i] == 1)
				count_paper[2]++;
		}
		return -2;
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> room[i][j];
		}
	}

	int return_value = paper(0, 0, N);
	if (return_value == -1)
		count_paper[0]++;
	else if (return_value == 0)
		count_paper[1]++;
	else if (return_value == 1)
		count_paper[2]++;

	for (int i = 0; i < 3; i++)
		cout << count_paper[i] << "\n";

	return 0;
}