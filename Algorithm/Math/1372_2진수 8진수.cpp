#include <iostream>
#include <string>
using namespace std;

string binNum;
string octNum;
int numSize;

string binToOct(char a, char b, char c)
{
	int bNum = 0;
	int mNum = 4;
	bNum += (a - '0') * mNum;
	mNum /= 2;
	bNum += (b - '0') * mNum;
	mNum /= 2;
	bNum += (c - '0') * mNum;
	return to_string(bNum);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> binNum;
	numSize = binNum.size();

	if (numSize % 3 == 1)
	{
		octNum += binToOct('0', '0', binNum[0]);
		for (int i = 1; i < numSize; i += 3)
		{
			octNum += binToOct(binNum[i], binNum[i + 1], binNum[i + 2]);
		}
	}
	else if (numSize % 3 == 2)
	{
		octNum += binToOct('0', binNum[0], binNum[1]);
		for (int i = 2; i < numSize; i += 3)
		{
			octNum += binToOct(binNum[i], binNum[i + 1], binNum[i + 2]);
		}
	}
	else
	{
		for (int i = 0; i < numSize; i += 3)
		{
			octNum += binToOct(binNum[i], binNum[i + 1], binNum[i + 2]);
		}
	}


	cout << octNum;

	return 0;
}

