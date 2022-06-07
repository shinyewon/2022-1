/* [평가항목 1] : 과제 설명

컴퓨터프로그래밍 평가과제 (배점 25점)
학과: 컴퓨터공학부
학번: 202201901
이름: 신예원

과제 주제: 코로나 지역별 확진자 현황

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "rank.h"

struct confirmed { // [평가항목 5] : 구조체 사용
	char name[20]; //지역이름
	int number;    //확진자수
};


int main(void)
{
	struct confirmed Gyeonggi = { "경기", 4939422 };
	struct confirmed* a; // [평가항목 4] : 포인터 사용 
	struct confirmed Seoul = { "서울", 3628593 };
	struct confirmed* b;
	struct confirmed Busan = { "부산", 1095430 };
	struct confirmed* c;

	a = &Gyeonggi;
	b = &Seoul;
	c = &Busan;

	int x = 0;
	printf("알고 싶은 지역의 번호를 입력하세요(0.경기, 1.서울, 2.부산): ");
	scanf("%d", &x);

	if (x == 0)
		printf("%s 지역의 누적확진자 수는 %d명입니다.\n", (*a).name, (*a).number);
	else if (x == 1)
		printf("%s 지역의 누적확진자 수는 %d명입니다.\n", (*b).name, (*b).number);
	else
		printf("%s 지역의 누적확진자 수는 %d명입니다.\n", (*c).name, (*c).number);

	rank(x); //순위 나타내주는 함수

	// [평가항목 7] : 파일 입출력
	FILE *fp;
	char fname[100];
	int number, date, count = 0;
	char name[20];

	printf("확진자 파일 이름을 입력하시오:  ");
	scanf("%s", fname);

	// 확진자 파일을 쓰기 모드로 연다.
	if ((fp = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "확진자 파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}


	// 사용자로부터 번호, 이름, 확진날짜를 입력받아서 파일에 저장한다.
	while (1)
	{
		printf("번호, 이름, 확진날짜를 입력하시요: (음수이면 종료)");
		scanf("%d", &number);
		if (number < 0) 
			break;
		scanf("%s %d", name, &date);
		fprintf(fp, " %d %s %d", number, name, date);

	}
	fclose(fp);

	// 확진자 파일을 읽기 모드로 연다.
	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "확진자 파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}

	// 파일을 읽어서 누적확진자수를 구한다.
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %d", &number, name, &date);
		count++;
	}

	printf("기록된 누적확진자수 = %d\n", count);
	fclose(fp);

	return 0;
}