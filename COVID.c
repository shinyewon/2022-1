/* [���׸� 1] : ���� ����

��ǻ�����α׷��� �򰡰��� (���� 25��)
�а�: ��ǻ�Ͱ��к�
�й�: 202201901
�̸�: �ſ���

���� ����: �ڷγ� ������ Ȯ���� ��Ȳ

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "rank.h"

struct confirmed { // [���׸� 5] : ����ü ���
	char name[20]; //�����̸�
	int number;    //Ȯ���ڼ�
};


int main(void)
{
	struct confirmed Gyeonggi = { "���", 4939422 };
	struct confirmed* a; // [���׸� 4] : ������ ��� 
	struct confirmed Seoul = { "����", 3628593 };
	struct confirmed* b;
	struct confirmed Busan = { "�λ�", 1095430 };
	struct confirmed* c;

	a = &Gyeonggi;
	b = &Seoul;
	c = &Busan;

	int x = 0;
	printf("�˰� ���� ������ ��ȣ�� �Է��ϼ���(0.���, 1.����, 2.�λ�): ");
	scanf("%d", &x);

	if (x == 0)
		printf("%s ������ ����Ȯ���� ���� %d���Դϴ�.\n", (*a).name, (*a).number);
	else if (x == 1)
		printf("%s ������ ����Ȯ���� ���� %d���Դϴ�.\n", (*b).name, (*b).number);
	else
		printf("%s ������ ����Ȯ���� ���� %d���Դϴ�.\n", (*c).name, (*c).number);

	rank(x); //���� ��Ÿ���ִ� �Լ�

	// [���׸� 7] : ���� �����
	FILE *fp;
	char fname[100];
	int number, date, count = 0;
	char name[20];

	printf("Ȯ���� ���� �̸��� �Է��Ͻÿ�:  ");
	scanf("%s", fname);

	// Ȯ���� ������ ���� ���� ����.
	if ((fp = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "Ȯ���� ���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}


	// ����ڷκ��� ��ȣ, �̸�, Ȯ����¥�� �Է¹޾Ƽ� ���Ͽ� �����Ѵ�.
	while (1)
	{
		printf("��ȣ, �̸�, Ȯ����¥�� �Է��Ͻÿ�: (�����̸� ����)");
		scanf("%d", &number);
		if (number < 0) 
			break;
		scanf("%s %d", name, &date);
		fprintf(fp, " %d %s %d", number, name, date);

	}
	fclose(fp);

	// Ȯ���� ������ �б� ���� ����.
	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "Ȯ���� ���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	// ������ �о ����Ȯ���ڼ��� ���Ѵ�.
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %d", &number, name, &date);
		count++;
	}

	printf("��ϵ� ����Ȯ���ڼ� = %d\n", count);
	fclose(fp);

	return 0;
}