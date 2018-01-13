#include <iostream>
#include <string>
using namespace std;

int main()
{
	string key;
	string sent;

	cin >> key;
	cin >> sent;

	string a[10][2];
	int compare[10];
	string temp;
	int tem;

	for (int i = 0; i < 10; i++)
	{
		compare[i] = i;
	}

	for (int i = 0; i < key.length(); i++)
	{
		a[i][0] = key.at(i);
	}

	for (int i = 0; i < key.length(); i++)
	{
		for (int j = 0; j < key.length() - 1; j++)
		{
			if (a[j][0] > a[j + 1][0])
			{
				temp = a[j][0];
				a[j][0] = a[j + 1][0];
				a[j + 1][0] = temp;
				tem = compare[j];
				compare[j] = compare[j + 1];
				compare[j + 1] = tem;
			}
		}
	}


	int sent_no = 0;
	for (int i = 0; i < key.length(); i++)
	{
		for (int j = 0; j < sent.length() / key.length(); j++)
		{
			a[i][1] += sent.at(sent_no++);
		}
	}

	for (int i = 0; i < key.length(); i++)
	{
		for (int j = 0; j < key.length() - 1; j++)
		{
			if (compare[j] > compare[j + 1])
			{
				temp = a[j][1];
				a[j][1] = a[j + 1][1];
				a[j + 1][1] = temp;
				tem = compare[j];
				compare[j] = compare[j + 1];
				compare[j + 1] = tem;
			}
		}
	}
	sent_no = 0;
	for (int i = 0; i < sent.length() / key.length(); i++)
	{
		for (int j = 0; j < key.length(); j++)
		{
			cout << a[j][1].at(i);
		}
	}

	return 0;
}