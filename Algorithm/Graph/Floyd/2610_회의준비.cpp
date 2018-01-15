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
	int leader_link_time = INF;	// 대표의 의사전달시간
	int leader_index = 0;	// 대표의 인덱스
	for (int i = 0; i < vec.size(); i++)
	{
		int max_link_time = 0;
		y = vec[i];
		for (int j = 0; j < vec.size(); j++)
		{
			x = vec[j];
			max_link_time = max(max_link_time, G[y][x]);	// 최대 의사전달시간 
		}
		if (leader_link_time > max_link_time)	// 최대 의사전달시간 중 최소값 탐색
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
		vector <int> v;		// 연결 요소 저장할 벡터
		for (int j = 1; j <= N; j++)
		{
			if (!check[j] && G[i][j] != INF)	// 방문한 적이 없고 연결되어있으면	벡터에 저장
			{
				v.push_back(j);
				check[j] = true;
			}
		}
		if (v.size() != 0)
			ans.push_back(search_leader(v));	// 대표 찾는 함수
	}

	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}


	return 0;
}