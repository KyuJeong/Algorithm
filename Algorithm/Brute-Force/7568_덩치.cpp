#include <iostream>
#include <vector>

using namespace std;

struct Size
{
	int x;
	int y;
	int rank = 1;
};

int main()
{
	int N;
	cin >> N;
	vector<Size> size(N);

	for (int i = 0; i < N; i++)
	{
		cin >> size[i].x >> size[i].y;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (size[i].x < size[j].x && size[i].y < size[j].y)
				size[i].rank++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", size[i].rank);
	}

	return 0;
}