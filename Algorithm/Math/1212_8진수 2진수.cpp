#include <iostream>
#include <string>
using namespace std;

string octNum;
int numSize;

void octToBin(char num)
{
	switch (num)
	{
	case '0':
		cout << "000";
		break;
	case '1':
		cout << "001";
		break;
	case '2':
		cout << "010";
		break;
	case '3':
		cout << "011";
		break;
	case '4':
		cout << "100";
		break;
	case '5':
		cout << "101";
		break;
	case '6':
		cout << "110";
		break;
	case '7':
		cout << "111";
		break;
	default:
		break;
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> octNum;
	numSize = octNum.size();

	switch (octNum[0])
	{
	case '0':
		cout << "0";
		break;
	case '1':
		cout << "1";
		break;
	case '2':
		cout << "10";
		break;
	case '3':
		cout << "11";
		break;
	case '4':
		cout << "100";
		break;
	case '5':
		cout << "101";
		break;
	case '6':
		cout << "110";
		break;
	case '7':
		cout << "111";
		break;
	default:
		break;
	}

	for (int i = 1; i < numSize; i++)
	{
		octToBin(octNum[i]);
	}

	return 0;
}