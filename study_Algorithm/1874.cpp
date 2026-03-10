//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int n, x;
int last = 0;
bool isNo = false;
stack<int> s;
char ans[200000];
int idx = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--)
	{
		cin >> x;
		// 1. last보다 크다면 입력 받은 수까지 push
		if (x > last)
		{
			for (int i = last + 1; i <= x; ++i)
			{
				s.push(i);
				// + 추가
				ans[idx++] = '+';
			}
			s.pop();
			ans[idx++] = '-';
			last = x;
		}

		// 2. last 보다 작다면
		else if (x < last)
		{
			// x보다 큰 수는 pop 하기
			while (!s.empty() && s.top() > x)
			{
				s.pop();
				ans[idx++] = '-';
			}

			// 실패 조건
			// 값이 비었거나 top 값과 일치하지 않을 때
			if (s.empty() || s.top() != x)
			{
				isNo = true;
			}
			// 나머지 성공
			else
			{
				s.pop();
				ans[idx++] = '-';
			}
		}
		else
		{
			isNo = true;
		}
	
	}

	if (isNo)
		cout << "NO";
	else
	{
		for (int i = 0; i < idx; ++i) {
			cout << ans[i] << '\n';
		}
	}
}