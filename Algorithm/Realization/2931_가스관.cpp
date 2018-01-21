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
int visit[26][26];	// 방문했는지 검사
bool find_start;	// 시작 지점을 찾았는지
char dst_block;		// 도착점이 'Z'인지 'M'인지
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };
bool is_delete;		// 지워진 지점을 찾았는지 
int block_count;	// 총 블럭 수
char utod[] = { '|','2','3','+' };	// 위->아래
char dtou[] = { '|','1','4','+' };	// 아래->위
char ltor[] = { '-','3','4','+' };	// 왼->오
char rtol[] = { '-','1','2','+' };	// 오->왼
Pt ans_point;	// 도착점 좌표
char ans_block;	// 도착점 블럭

Pt FindRoute(Pt pre, Pt cur, char block)
{
	int py = pre.y; int px = pre.x;
	int cy = cur.y;	int cx = cur.x;

	switch (block)
	{
	case '|':
		if (py < cy)	// 위->아래
			return Pt(cy + 1, cx);
		else
			return Pt(cy - 1, cx);
		break;
	case '-':
		if (px < cx)	// 왼->오
			return Pt(cy, cx + 1);
		else
			return Pt(cy, cx - 1);
		break;
	case '+':
		if (py < cy)	// 위->아래
			return Pt(cy + 1, cx);
		else if (py > cy)	// 아래->위
			return Pt(cy - 1, cx);
		else if (px < cx)	// 왼->오
			return Pt(cy, cx + 1);
		else   // 오->왼
			return Pt(cy, cx - 1);
		break;
	case '1':
		if (py > cy) // 아래->위
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
					if (i == 3)	// 세 개 다 넣어보고 아닌 경우 그 자리엔 무조건 '+'가 와야 함
					{
						ans_point = cur;
						ans_block = '+';
						return true;
					}

					char cur_block;	// 하나씩 넣어보고 정답인지 확인
					if (py < cy)
						cur_block = utod[i];
					else if (py > cy)
						cur_block = dtou[i];
					else if (px < cx)
						cur_block = ltor[i];
					else
						cur_block = rtol[i];

					nxt = FindRoute(pre, cur, cur_block);

					if (FlowGas(cur, nxt, count + 1))	// 정답을 찾은 경우
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
			if (count == block_count)	// 도착점에 도착하고 모든 블럭을 지나왔을 경우 정답
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
			nxt = FindRoute(pre, cur, G[cy][cx]);	// 다음 파이프를 따라감
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

	if (!find_start)	// 시작점 근처에 파이프가 없는 경우 도착점 기준으로 탐색
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

	if (!find_start)	// 아직 시작점을 못 찾은 경우	시작점과 도착점 사이 블럭이 하나밖에 없음
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