#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k;
	string bulbs;

	cin >> n >> k;
	cin.ignore();
	getline(cin, bulbs);

	int idx=0;

	for (int i=0; i<n; i++)
		if (bulbs[i]=='1')
		{
			idx=i;
			break;
		}
	
	int l=1, operations=0;

	for (int i=idx; i<n;i++)
	{
		if (bulbs[i]!='1')
			continue;

		operations++;

		if (operations>k)
		{
			operations=0;
			l++;
			i=idx-1;
		}

		else
			i+=(l-1);
	}
	
	cout << l;
    
	return 0;
}