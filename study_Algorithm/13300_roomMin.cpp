//#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned int n, k;
	bool boy = 0;
	unsigned int arr[2][7] = {};

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		++arr[a][b];
	}

	int sum = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			sum += arr[i][j] / k;
			if (arr[i][j] % k)++sum;
		}
	}

	cout << sum;
}
