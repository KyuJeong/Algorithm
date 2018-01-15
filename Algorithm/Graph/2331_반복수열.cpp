#include <iostream>
#include <math.h>
using namespace std;

int A, P;
int D[10000];

int main()
{
	std::ios::sync_with_stdio(false);
	int idx = 2;
	int overlap_index = 0;
	cin >> A >> P;

	D[1] = A;

	while (overlap_index == 0)	// ����Ŭ �߻� ������ �ݺ�
	{
		for (int quo = D[idx - 1]; quo > 0; quo /= 10)	// D[n]�� �ϳ��� ä������
		{
			D[idx] += pow(quo % 10, P);
		}

		for (int i = 1; i < idx; i++)	// ����Ŭ �߻� ���� Ž��
		{
			if (D[idx] == D[i])
			{
				overlap_index = i;	// ����Ŭ �߻� ���� ����
				break;
			}
		}
		idx++;
	}

	cout << overlap_index - 1;


	return 0;
}