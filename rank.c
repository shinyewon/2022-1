// [���׸� 8] : ���߼ҽ� ���� ���
#include "rank.h"

//������ ������ �迭
int A = 4939422, B = 3628593, C = 1095430, i, n; //��� ���� �λ�
int *api[3] = { &A, &B, &C }; //[���׸� 6] : ������ Ȱ��, [���׸� 3] : �迭 ���
n = sizeof(api) / sizeof(api[0]); //�迭 ���� ���� ���

//[���׸� 2] : �Լ� ���
int rank(int user_num)
{
	int place = 1;
	for (i = 0; i < n; i++) {
		if (*api[user_num] < *api[i]) {
			place++;
		}
	}
	printf("������ ������ ����Ȯ���� �� ������ %d�Դϴ�.\n", place);
	return 0;
}