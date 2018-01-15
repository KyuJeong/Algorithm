#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 99999999

int N, M, K;
int G[101][101];
int temp1, temp2;
bool check[101];
vector <int> ans;

int search_leader(vector<int> vec)
{
	int y, x;
	int leader_link_time = INF;	// ��ǥ�� �ǻ����޽ð�
	int leader_index = 0;	// ��ǥ�� �ε���
	for (int i = 0; i < vec.size(); i++)
	{
		int max_link_time = 0;
		y = vec[i];
		for (int j = 0; j < vec.size(); j++)
		{
			x = vec[j];
			max_link_time = max(max_link_time, G[y][x]);	// �ִ� �ǻ����޽ð� 
		}
		if (leader_link_time > max_link_time)	// �ִ� �ǻ����޽ð� �� �ּҰ� Ž��
		{
			leader_link_time = max_link_time;
			leader_index = y;
		}
	}
	return leader_index;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			G[i][j] = INF;
			if (i == j)
				G[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		G[temp1][temp2] = 1;
		G[temp2][temp1] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		vector <int> v;		// ���� ��� ������ ����
		for (int j = 1; j <= N; j++)
		{
			if (!check[j] && G[i][j] != INF)	// �湮�� ���� ���� ����Ǿ�������	���Ϳ� ����
			{
				v.push_back(j);
				check[j] = true;
			}
		}
		if (v.size() != 0)
			ans.push_back(search_leader(v));	// ��ǥ ã�� �Լ�
	}

	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}


	return 0;
}