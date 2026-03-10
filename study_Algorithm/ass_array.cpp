#include <iostream>
#include "ass_array.h"

void InitArr(tArr* pArr)
{
	pArr->pInt = (int*)malloc(sizeof(int) * 2);
	pArr->iCount = 0;
	pArr->iMaxCount = 2;
}

void ReallocateArr(tArr* pArr)
{
	// 1. 새로운 배열 생성
	int* pNew = (int*)malloc(sizeof(int) * 2 * pArr->iMaxCount);

	// 2. 기존 데이터 복사
	for (int i = 0; i < pArr->iCount; ++i)
	{
		pNew[i] = pArr->pInt[i];
	}

	// 3. 기존 메모리 해제
	free(pArr->pInt);

	// 4. 새로운 배열로의 주소
	pArr->pInt = pNew;

	// 5. iMaxCount 증가
	pArr->iMaxCount *= 2;
}

void AddArr(tArr* pArr, int iData)
{
	// 1. 이미 공간이 꽉 찼는지 체크
	if (pArr->iCount == pArr->iMaxCount)
	{
		// 재할당
		ReallocateArr(pArr);
	}

	// 2. 데이터 추가
	pArr->pInt[pArr->iCount++] = iData;
}

void ReleaseArr(tArr* pArr)
{
	free(pArr->pInt);
	pArr->iCount = 0;
	pArr->iMaxCount = 0;
}

void BubbleSort(tArr* pArr)
{
	// 데이터가 1개 이하면 정렬하지 않음
	if (pArr->iCount <= 1)
		return;

	for (int i = 0; i < pArr->iCount - 1; ++i)
	{
		for (int j = 0; j < pArr->iCount - 1 - i; ++j) {
			if (pArr->pInt[j] > pArr->pInt[j + 1])
			{
				int tmp = pArr->pInt[j];
				pArr->pInt[j] = pArr->pInt[j + 1];
				pArr->pInt[j + 1] = tmp;
			}
		}
	}
}

void PrintArr(tArr* pArr)
{
	std::cout << "<Array>\n";
	for (int i = 0; i < pArr->iCount; ++i)
	{
		std::cout << pArr->pInt[i] << " ";
	}
	std::cout << "\n";
}
