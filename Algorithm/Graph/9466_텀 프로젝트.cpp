#include <iostream>
using namespace std;

#define MAX 100001

int T, N;
int stnt[MAX];
int cycle_cnt[MAX];
int graph_idx[MAX];

int DFS(int idx)
{
	int cur = idx;
	graph_idx[cur] = idx;	// 처음 DFS 호출을 시작한 index를 저장

	int cnt = 1;	// cycle 안에 몇 명이 있는지

	while (1)
	{
		cur = stnt[cur];	// 다음 학생을 가리킴

		if (graph_idx[cur] == idx)	//	이번 DFS에서 호출된 인덱스가 다시 호출됐다면 싸이클 발생
			return cnt - cycle_cnt[cur];	// 싸이클 안의 학생 수 리턴
		else if (graph_idx[cur] != 0)	// 다른 DFS에서 호출돼었던 인덱스를 가리킨다면
			return 0;	// 싸이클이 일어날 수 없으므로 종료

		cycle_cnt[cur] = cnt;
		graph_idx[cur] = idx;
		cnt++;
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N;

		int can_join = 0;

		for (int i = 1; i <= N; i++)
		{
			cin >> stnt[i];
			cycle_cnt[i] = 0;
			graph_idx[i] = 0;
		}

		for (int i = 1; i <= N; i++)
		{
			if (graph_idx[i] == 0)
				can_join += DFS(i);
		}

		cout << N - can_join << "\n";
	}

	return 0;
}