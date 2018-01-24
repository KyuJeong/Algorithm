#include <iostream>
#include <string>
using namespace std;

string sik;
int plusSum, minusSum;
bool isMinus;
string subsik;
int startIndex;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> sik;

	for (int i = 0; i < sik.size(); i++)
	{
		if (!isMinus)
		{
			if (sik[i] == '+')
			{
				subsik = sik.substr(startIndex, i);
				startIndex = i + 1;
				plusSum += atoi(subsik.c_str());
			}
			else if (sik[i] == '-')
			{
				subsik = sik.substr(startIndex, i);
				startIndex = i + 1;
				plusSum += atoi(subsik.c_str());
				isMinus = true;
				i++;
			}
		}
		else
		{
			if (sik[i] == '+' || sik[i] == '-')
			{
				subsik = sik.substr(startIndex, i);
				startIndex = i + 1;
				minusSum += atoi(subsik.c_str());
			}
		}
	}

	subsik = sik.substr(startIndex, sik.size());
	if (isMinus)
		minusSum += atoi(subsik.c_str());
	else
		plusSum += atoi(subsik.c_str());

	cout << plusSum - minusSum;

	return 0;
}