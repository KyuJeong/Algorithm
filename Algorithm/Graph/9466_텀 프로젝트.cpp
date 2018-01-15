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
	graph_idx[cur] = idx;	// ó�� DFS ȣ���� ������ index�� ����

	int cnt = 1;	// cycle �ȿ� �� ���� �ִ���

	while (1)
	{
		cur = stnt[cur];	// ���� �л��� ����Ŵ

		if (graph_idx[cur] == idx)	//	�̹� DFS���� ȣ��� �ε����� �ٽ� ȣ��ƴٸ� ����Ŭ �߻�
			return cnt - cycle_cnt[cur];	// ����Ŭ ���� �л� �� ����
		else if (graph_idx[cur] != 0)	// �ٸ� DFS���� ȣ��ž��� �ε����� ����Ų�ٸ�
			return 0;	// ����Ŭ�� �Ͼ �� �����Ƿ� ����

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