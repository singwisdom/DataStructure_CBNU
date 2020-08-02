#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count=0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ',')

			count += 1;
	}

	cout << count+1;
}