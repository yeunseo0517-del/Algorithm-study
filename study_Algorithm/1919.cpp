//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;

	cin >> s1 >> s2;

	int arr[26] = {};
	for (auto i : s1)
		++arr[i - 'a'];
	for (auto i : s2)
		--arr[i - 'a'];

	int cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (arr[i]) cnt += abs(arr[i]);
	}

	cout << cnt;
}