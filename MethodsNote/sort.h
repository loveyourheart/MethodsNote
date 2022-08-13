#pragma once
#include "ElemType.h"
void InsertSort(ElemType A[], int n) {

	int i, j;
	ElemType temp;
	for (i = 1; i <= n-1; i++)
		if (A[i] < A[i-1]) {
			 temp= A[i];
			 for (j = i - 1; compareElem(temp, A[j] )== -1; --j) {
				A[j + 1] = A[j];
			}
			A[j + 1] = temp;
		}
	printf("\n");
}
void bubblingSort(ElemType a[], int n) {
	int i, j;
	ElemType temp;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (IsMore(a[j] , a[j + 1])) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int Partition(ElemType A[], int left, int right) {
	ElemType temp =A[left];
	while (left < right) {
		while (left < right && compareElem(A[right], temp) == 1) right--;
		A[left] = A[right];
		while(left < right&& compareElem(A[left], temp) < 1) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
void quickSort(ElemType A[], int left, int right) {
	if (left < right) {
		int pos = Partition(A, left, right);
		quickSort(A, left, pos - 1);
		quickSort(A,pos+1,right);

	}
}