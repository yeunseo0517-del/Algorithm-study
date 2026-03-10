#include <iostream>
#include <time.h>
#include "ass_array.h"


int main()
{
	tArr s;

	InitArr(&s);

	// 시드 값을 통해 난수 변경
	// 임의의 페이지로부터 가져옴
	// 하지만 동일 시드라면 값이 같아질 수 있으므로 시간 값을 넣어 다르게 만듦
	// 시간이 같아지면 값이 같아지는 단점으로 쉐이더에서는 문제 발생 가능
	srand(time(nullptr));

	for (int i = 0; i < 10; ++i)
	{
		// 난수(랜덤)
		// 랜덤 값이 적혀 있는 페이지로부터 가져옴
		// 하지만 순서적으로 불러온다는 단점 존재 -> 완전한 무작위 X
		// 1~100
		int iRandom = rand() % 100 + 1;
		AddArr(&s, iRandom);
	}

	PrintArr(&s);

	BubbleSort(&s);

	std::cout << "After sorting ...\n";

	PrintArr(&s);

	ReleaseArr(&s);

	return 0;
}