//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s1, s2;
		int freq1[26] = {};
		int freq2[26] = {};
		bool Impossible = false;
		cin >> s1 >> s2;

		for (auto x : s1)
			++freq1[x - 'a'];

		for (auto x : s2)
			++freq2[x - 'a'];

		for (int j = 0; j < 26; ++j)
		{
			if (freq1[j] != freq2[j])
			{
				Impossible = true;
				break;
			}
		}

		if (Impossible)
			cout << "Impossible\n";
		else
			cout << "Possible\n";
	}
}