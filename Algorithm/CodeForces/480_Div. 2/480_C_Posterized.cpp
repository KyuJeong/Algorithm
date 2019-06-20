#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int n, k;
int arr[100001];
bool choose[256];
int grp[256];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(grp, -1, sizeof(grp));

	bool start = true;
	int _min, _max;

	for (int i = 0; i < n; i++)
	{
		int num = arr[i];
		if (grp[num] != -1)
		{
			cout << grp[num] << " ";
		}

		else
		{
			int _min = num;
			for (int j = 0; j < k; j++)	// k-1��ŭ ���̳������� �˻�
			{
				if (num - j < 0)	// num - j�� 0���� �۾�����
					break;
				if (grp[num - j] != -1)	// num - j�� �̹� �׷쿡 ����������
				{
					if (num - grp[num - j] < k)		// �� �׷쿡 ���� �� ������ �� �׷��� Ű���� �ּڰ��̴�.
					{
						grp[num] = grp[num - j];
						_min = grp[num - j];
						break;
					}
					else        // �� �׷쿡 ���� �� ���ٸ� [�� �� ����, num] �׷� ����
					{
						grp[num] = num;		
						break;
					}
				}
				else // num - j�� �׷쿡 �������� �ʴٸ� �ּڰ����� �����Ѵ�.
				{
					_min = num - j;
				}
			}
			for (int j = _min; j <= num; j++)	// �ּڰ��� Ű������ [�ּڰ�, ���簪] �׷� ����
				grp[j] = _min;
			cout << grp[num] << " ";
		}
	}

	return 0;
}