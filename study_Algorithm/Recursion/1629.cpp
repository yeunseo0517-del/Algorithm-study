#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Pow(int x, int y, int mod)
{
	if (y == 1) return x % mod;

	ll val = Pow(x, y / 2, mod);

	//val >= mod 가 될 수 있으므로 %mod 한번 더
	val = val * val % mod;

	if (y % 2 == 0)
		return val;
	else
		return val * x % mod;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	ll mod = Pow(A, B, C);

	cout << mod;
}