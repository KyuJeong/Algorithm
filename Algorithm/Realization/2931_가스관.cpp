#include <iostream>
#include <queue>

using namespace std;

struct Pt
{
	int y, x;
	Pt() {};
	Pt(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

int R, C;
char G[26][26];
int visit[26][26];	// �湮�ߴ��� �˻�
bool find_start;	// ���� ������ ã�Ҵ���
char dst_block;		// �������� 'Z'���� 'M'����
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };
bool is_delete;		// ������ ������ ã�Ҵ��� 
int block_count;	// �� �� ��
char utod[] = { '|','2','3','+' };	// ��->�Ʒ�
char dtou[] = { '|','1','4','+' };	// �Ʒ�->��
char ltor[] = { '-','3','4','+' };	// ��->��
char rtol[] = { '-','1','2','+' };	// ��->��
Pt ans_point;	// ������ ��ǥ
char ans_block;	// ������ ��

Pt FindRoute(Pt pre, Pt cur, char block)
{
	int py = pre.y; int px = pre.x;
	int cy = cur.y;	int cx = cur.x;

	switch (block)
	{
	case '|':
		if (py < cy)	// ��->�Ʒ�
			return Pt(cy + 1, cx);
		else
			return Pt(cy - 1, cx);
		break;
	case '-':
		if (px < cx)	// ��->��
			return Pt(cy, cx + 1);
		else
			return Pt(cy, cx - 1);
		break;
	case '+':
		if (py < cy)	// ��->�Ʒ�
			return Pt(cy + 1, cx);
		else if (py > cy)	// �Ʒ�->��
			return Pt(cy - 1, cx);
		else if (px < cx)	// ��->��
			return Pt(cy, cx + 1);
		else   // ��->��
			return Pt(cy, cx - 1);
		break;
	case '1':
		if (py > cy) // �Ʒ�->��
			return Pt(cy, cx + 1);
		else
			return Pt(cy + 1, cx);
		break;
	case '2':
		if (py < cy)
			return Pt(cy, cx + 1);
		else
			return Pt(cy - 1, cx);
		break;
	case '3':
		if (py < cy)
			return Pt(cy, cx - 1);
		else
			return Pt(cy - 1, cx);
		break;
	case '4':
		if (py > cy)
			return Pt(cy, cx - 1);
		else
			return Pt(cy + 1, cx);
		break;
	}
}

bool FlowGas(Pt _pre, Pt _cur, int _count)
{
	Pt pre = _pre;
	Pt cur = _cur;
	int count = _count;
	Pt nxt;

	while (1)
	{
		int py = pre.y; int px = pre.x;
		int cy = cur.y;	int cx = cur.x;
		if (cy <= 0 || cx <= 0 || cy > R || cx > C)
			return false;
		if (G[cy][cx] == '.')
		{
			if (!is_delete)
			{
				is_delete = true;
				for (int i = 0; i < 4; i++)
				{
					if (i == 3)	// �� �� �� �־�� �ƴ� ��� �� �ڸ��� ������ '+'�� �;� ��
					{
						ans_point = cur;
						ans_block = '+';
						return true;
					}

					char cur_block;	// �ϳ��� �־�� �������� Ȯ��
					if (py < cy)
						cur_block = utod[i];
					else if (py > cy)
						cur_block = dtou[i];
					else if (px < cx)
						cur_block = ltor[i];
					else
						cur_block = rtol[i];

					nxt = FindRoute(pre, cur, cur_block);

					if (FlowGas(cur, nxt, count + 1))	// ������ ã�� ���
					{
						ans_point = cur;
						ans_block = cur_block;
						return true;
					}
				}
			}
			else
				return false;
		}
		else if (G[cy][cx] == dst_block)
		{
			if (count == block_count)	// �������� �����ϰ� ��� ���� �������� ��� ����
				return true;
			else
				return false;
		}
		else
		{
			if (!is_delete)
				visit[cy][cx]++;
			else
			{
				if (G[cy][cx] == '+')
				{
					if (visit[cy][cx] == 2)
						return false;
				}
				else
				{
					if (visit[cy][cx] == 1)
						return false;
				}
			}
			count++;
			nxt = FindRoute(pre, cur, G[cy][cx]);	// ���� �������� ����
			pre = cur;
			cur = nxt;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> R >> C;
	Pt src, dst;
	Pt pre, start;
	
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++) 
		{
			cin >> G[i][j];
			if (G[i][j] == 'M')
			{
				src.y = i;
				src.x = j;
			}
			else if (G[i][j] == 'Z')
			{
				dst.y = i;
				dst.x = j;
			}
			else if (G[i][j] == '+')
				block_count += 2;
			else if (G[i][j] != '.')
				block_count++;
		}
	}

	block_count++;

	int cy = src.y; int cx = src.x;
	int dy = dst.y;	int dx = dst.x;

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + my[i]; 
		int nx = cx + mx[i];
		if (ny <= 0 || nx <= 0 || ny > R || nx > C)
			continue;
		if (G[ny][nx] != '.' && G[ny][nx] != 'Z')
		{
			start = Pt(ny, nx);
			pre = src;
			find_start = true;
			visit[cy][cx]++;
			dst_block = 'Z';
		}
	}

	if (!find_start)	// ������ ��ó�� �������� ���� ��� ������ �������� Ž��
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = dy + my[i];
			int nx = dx + mx[i];
			if (ny <= 0 || nx <= 0 || ny > R || nx > C)
				continue;
			if (G[ny][nx] != '.' && G[ny][nx] != 'M')
			{
				start = Pt(ny, nx);
				pre = dst;
				find_start = true;
				visit[cy][cx]++;
				dst_block = 'M';
			}
		}
	}

	if (!find_start)	// ���� �������� �� ã�� ���	�������� ������ ���� ���� �ϳ��ۿ� ����
	{
		if (cx == dx)
		{
			ans_point.y = (cy + dy) / 2;
			ans_point.x = dx;
			ans_block = '|';
		}
		else
		{
			ans_point.y = dy;
			ans_point.x = (cx + dx) / 2;
			ans_block = '-';
		}
	}
	else
		FlowGas(pre, start, 0);

	cout << ans_point.y << " " << ans_point.x << " " << ans_block;

	return 0;
}