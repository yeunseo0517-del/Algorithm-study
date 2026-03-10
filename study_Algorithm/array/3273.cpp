//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int arr[100000] = {};
bool occur[2000001] = {};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> x;
	
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (x - arr[i] > 0 && occur[x - arr[i]])
			cnt++;
		occur[arr[i]] = true;
	}

	cout << cnt;
}