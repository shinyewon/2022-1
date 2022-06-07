// [평가항목 8] : 다중소스 파일 사용
#include "rank.h"

//정수형 포인터 배열
int A = 4939422, B = 3628593, C = 1095430, i, n; //경기 서울 부산
int *api[3] = { &A, &B, &C }; //[평가항목 6] : 포인터 활용, [평가항목 3] : 배열 사용
n = sizeof(api) / sizeof(api[0]); //배열 원소 개수 계산

//[평가항목 2] : 함수 사용
int rank(int user_num)
{
	int place = 1;
	for (i = 0; i < n; i++) {
		if (*api[user_num] < *api[i]) {
			place++;
		}
	}
	printf("선택한 지역의 누적확진자 수 순위는 %d입니다.\n", place);
	return 0;
}