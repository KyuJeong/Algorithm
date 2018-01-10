#include <iostream>

using namespace std;

int n;
int tmp;
bool non_leaf[1001];
int parent[1001];
int child[1001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		cin >> tmp;
		non_leaf[tmp] = true; // �ڽ��� ����� ������ �ƴ�
		parent[i] = tmp;	// i�� �θ� ��������
		child[tmp]++;	// tmp�� �ڽ� ���� ������Ŵ
	}
	
	for (int i = 2; i <= n; i++)
	{
		if (non_leaf[i])
			child[parent[i]]--;
	}

	for (int i = 1; i <= n; i++)
	{
		if (non_leaf[i] && child[i] < 3)
		{
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";

	return 0;
}