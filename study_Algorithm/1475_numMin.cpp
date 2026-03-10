//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int freq[9] = {};
	cin >> s;

	// 1. 0 ~ 9까지 각 몇 개의 숫자가 있는지 체크
	for (auto i : s)
	{
		// 6과 9 예외 처리
		if (i - '0' == 9)
			freq[6]++;
		else
			freq[i - '0']++;
	}

	freq[6] = (freq[6] + 1) / 2;

	// 2. 가장 높은 값 찾아내기
	int max = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (freq[i] > max)
			max = freq[i];
	}

	cout << max;
}