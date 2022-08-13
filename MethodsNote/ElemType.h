#pragma once
#include<stdio.h>
#include <malloc.h>
#include "define.h"
#include "oftenUseBaseData.h"
typedef int ElemType;
void printfElemType(int e) {
	 printf("%d ", e);
}
void printfElemType(int a[],int n) {
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
}
void printfElemType(double e) {
	printf("%6.6f ", e);
}
void printfElemType(double a[], int n) {
	for (int i = 0; i < n; i++) printf("%.6f ", a[i]);
	printf("\n");
}
void printfElemType(char c) {
	printf("%c", c);
}
void printfElemType(char a[], int n) {
	for (int i = 0; i < n; i++) printf("%c ", a[i]);
	printf("\n");
}
int IsEqual(int s, int t) {
	if (s == t) {
		return 1;
	}
	return 0;
}
int IsEqual(double s, double t) {
	if (Equ(s, t)) return 1;
	return 0;
}
int IsEqual(char s, char t) {
	if (s == t) {
		return 1;
	}
	return 0;
}
int IsMore(int s, int t) {
	if (s > t) return 1;
	return 0;
}
int IsMore(double s, double t) {
	if (More(s,t)) return 1;
	return 0;
}
int IsMore(char s, char t) {
	if (s > t) return 1;
	return 0;
}
int IsLess(int s, int t) {
	if (s<t) return 1;
	return 0;
}
int IsLess(double s,double t) {
	if (Less(s, t)) return 1;
	return 0;
}
int IsLess(char s, char t) {
	if (s < t) return 1;
	return 0;
}
int IsLessEqual(int s,int t) {
	if (!IsMore(s, t)) return 1;
	return 0;
}
int IsLessEqual(double s, double t) {
	if (!IsMore(s, t)) return 1;
	return 0;
}
int IsLessEqual(char s, char t) {
	if (!IsMore(s, t)) return 1;
	return 0;
}
int IsMorequal(int s, int t) {
	if (!IsLess(s, t)) return 1;
	return 0;
}
int IsMorequal(double s, double t) {
	if (!IsLess(s, t)) return 1;
	return 0;
}
int IsMorequal(char s, char t) {
	if (!IsLess(s, t)) return 1;
	return 0;
}
int compareElem(int  s, int t) {
	if (s == t) {
		return 0;
	}
	else {
		if (IsMore(s,t)) {
			return 1;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
int compareElem(double  s, double t) {
	if (Equ(s,t)) {
		return 0;
	}
	else {
		if (More(s,t)) {
			return 1;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
int compareElmem(char  s,char t) {
	if (s == t) {
		return 0;
	}
	else {
		if (IsMore(s, t)) {
			return 1;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
int merge(ElemType A[], ElemType B[], ElemType C[], int n, int m) {
	int i = 0, j = 0, index = 0;
	while (i < n && j < m) {
		if (IsLessEqual(A[i] ,B[j])) {
			C[index++] = A[i++];
		}
		else {
			C[index++] = B[j++];
		}
	}
	while (i < n)
	{
		C[index++] = A[i++];

	}
	while (j < m)
	{
		C[index++] = B[j++];
	}
	return index;
}