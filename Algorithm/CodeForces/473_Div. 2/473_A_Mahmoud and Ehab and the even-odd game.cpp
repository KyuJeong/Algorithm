#include <iostream>

using namespace std;

int n;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	if (n == 1)
	{
		cout << "Ehab";
	}
	else if (n % 2 == 0)
	{
		cout << "Mahmoud";
	}	
	else
	{
		cout << "Ehab";
	}


	return 0;
}