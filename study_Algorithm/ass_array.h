#pragma once

typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
} tArr;

// 배열 초기화 함수
void InitArr(tArr* pArr);

// 데이터 추가 함수
void AddArr(tArr* pArr, int iData);

// 메모리 해제 함수
void ReleaseArr(tArr* pArr);

// 버블 정렬 함수
void BubbleSort(tArr* pArr);

// 배열 출력 함수
void PrintArr(tArr* pArr);