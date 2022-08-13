#pragma once
#include<stdio.h>
#include<algorithm>
#include "define.h"
using namespace std;
void intType() {
	int a = 1, b = 2;
	printf("%d\n", a + b);
}
void doubleType() {
	double a = 3.14, b = 0.12;
	double c = a + b;
	printf("%.3f", c);
}
void charType() {
	int num1 = 1, num2 = 2;
	printf("%d\n\n%d", num1, num2);
	printf("%c", 7);

}
void strType() {
	char str1[25] = "Wo ai de ren bu ai wo";
	char str2[25] = "so sad a story it is.";
	printf("%s,%s", str1, str2);
}
void memestTest() {
	int a[5] = { 1,2,3,4,5 };
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
}
void getcharTest() {
	char str[5][5];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			str[i][j] = getchar();
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			putchar(str[i][j]);
		}
		printf("\n");
	}
}
void getsTest() {
	char str1[20];
	gets_s(str1);
	printf("%s", str1);
}
void strlenTest() {
	char str1[20];
	gets_s(str1, 10);
	int len = strlen(str1);
	printf("%d\n", len);
}
void strcmpTest() {
	char str1[50], str2[50];
	gets_s(str1, 50);
	gets_s(str2, 50);
	int cmp = strcmp(str1, str2);
	if (cmp < 0) printf("str1 < str2");
	else if (cmp > 0) printf("str1 > str2");
	else printf("str1 == str2");

}
void strcpyTest() {
	char str1[50], str2[50];
	gets_s(str1, 50);
	gets_s(str2, 50);
	strcpy(str1, str2);
	puts(str1);
}
void strcatTest() {
	char str1[50], str2[50];
	gets_s(str1, 50);
	gets_s(str2, 50);
	strcat(str1, str2);
	puts(str1);
}
void sscanfTest() {
	int n;
	char str[100] = "123";
	sscanf(str, "%d", &n);
	printf("%d\n", n);
}
void sprintfTest() {
	int n = 233;
	char str[100];
	sprintf(str, "%d", n);
	printf("%s\n", str);
}

void t__Test() {
	int T, a, n;
	scanf_s("%d", &T);
	while (T--) {
		int sum = 0;
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &a);
			sum = sum + a;
		}
		printf("%d\n", sum);
		if (T > 0) printf("\n");
	}
}

void eofTest() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}
}


void equTest() {
	double db = 1.23;
	if (Equ(db, 1.23)) {
		printf("true");
	}
	else {
		printf("false");
	}
}
void equTest2() {
	double db1 = 4*asin(sqrt(2.0) / 2);
	double db2 = 3 * asin(sqrt(3.0) / 2);
	if (db1==db2) {
		printf("true");
	}
	else {
		printf("false");
	}
}

void moreTest() {
	double db1 = 4 * asin(sqrt(2.0) / 2)+0.001;
	double db2 = 3 * asin(sqrt(3.0) / 2);
	if(More(db1,db2)){
		printf("true");
	}
	else {
		printf("false");
	}
}

void threeNum(int A[],int n, int target, int B[3]) {
	int k = 0, i = 1,j=n-1,temp;
	int t = 0;
	for (; k < n-2; k++) {
		temp = target - A[k];
		i = k + 1;
		j = n - 1;
		while (i < j) {
			if (A[i] + A[j] == temp) {
				B[0] = k;
				B[1] = i;
				B[2] = j;
				i++;
				j--;
				printf("%d %d %d", B[0], B[1], B[2]);
			}
			else {
				if (A[i] + A[j] > temp) {
					j--;
				}
				else
				{
					i++;
				}
			}
		}
	}
	
}
void threeNumTest() {
	int A[50] = { -1 }, B[3] = { -1 };
	int n, target,t=0;
	printf("输入数组A的长度n:");
	scanf("%d", &n);
	printf("输入数组A,以空格分隔，A:");
	for (int i = 0; i < n; i++) {
		scanf("%d", A+i);
	}
	sort(A, A + n);
	getchar();
	printf("输入目标数：");
	scanf("%d", &target);
	threeNum(A, n, target, B);
	
}