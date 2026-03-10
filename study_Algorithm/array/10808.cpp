//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int arr[26] = {};
	for(auto i : s){
		arr[i - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}
}