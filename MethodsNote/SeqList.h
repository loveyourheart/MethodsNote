#pragma once
#include "ElemType.h"
#include "sort.h"
#include "define.h"
#include "oftenUseBaseData.h"
typedef struct {
	ElemType data[SeqListMaxSize];
	int length;
}SeqList;
void initiateSeqList(SeqList* seq) {
	seq->length = 0;
}
int insertSeqList(SeqList* seq,int k, ElemType e) {
	if (k<1 || k>seq->length+1||seq->length>=SeqListMaxSize) {
		return 0;
	}
	for (int i = seq->length; i>=k; i--) {
		seq->data[i] = seq->data[i-1];
	}
	seq->data[k-1] = e;
	seq->length++;
	return 1;
}
int deleteSeqList(SeqList* seq, int k, ElemType *e) {
	if (k<1 || k>seq->length) {
		return 0;
	}
	*e = seq->data[k-1];
	for (int i=k; i <seq->length; i++) {
		seq->data[i-1] = seq->data[i];
	}
	seq->length = seq->length - 1;
    
	return 1;
}
int getSeqListElem(SeqList L, int k, ElemType* e) {
	if (k<1 || k>L.length)
	{
		return 0;
	}
	else {
		*e = L.data[k - 1];
		return 1;
	}
}
void deleteRange(SeqList& L, int i, int j) {
	i = i - 1; j = j - 1;
	if (0 <= i && 0 <= j && i < L.length && j < L.length) {

	}
	// 用j+1后面的元素去覆盖往前数第j-i+1个元素
	int delta = j - i + 1;
	for (int k = j + 1; k < L.length; ++k) {
		L.data[k - delta] = L.data[k];
	}
	L.length -= delta;
}
int deleteSeqListMinValue(SeqList* L, ElemType* e, int* t) {
	//使用最后一位值替换

	if (L->length == 0) {
		printf("顺序表为空");
		return 0;
	}
	ElemType minElemValue, temp;
	int locate = 1;
	getSeqListElem(*L, 1, &minElemValue);
	for (int i = 2; i <= L->length; i++) {
		getSeqListElem(*L, i, &temp);
		if (compareElem(temp, minElemValue) < 0) {
			minElemValue = temp;
			locate = i;
		}
	}
	*t = locate;
	deleteSeqList(L, locate, &minElemValue);
	printf("删除值的位置是%d ,值是%d\n", locate, minElemValue);
	*e = minElemValue;
	return 1;
}
int deleteSeqListMaxValue(SeqList* L, ElemType* e, int* t) {
	//使用最后一位值替换

	if (L->length == 0) {
		printf("顺序表为空");
		return 0;
	}
	ElemType maxElemValue, temp;
	int locate = 1;
	getSeqListElem(*L, 1, &maxElemValue);
	for (int i = 2; i <= L->length; i++) {
		getSeqListElem(*L, i, &temp);
		if (compareElem(temp, maxElemValue) ==1) {
			maxElemValue = temp;
			locate = i;
		}
	}
	*t = locate;
	deleteSeqList(L, locate, &maxElemValue);
	printf("删除值的位置是%d ,值是%d\n", locate, maxElemValue);
	*e = maxElemValue;
	return 1;
}
int LocationElem(SeqList L, ElemType e) {
	int i = 0;
	for (i = 0; i < L.length; i ++) {
		if (IsEqual(L.data[i], e) ){
			return i+1;
		}

	}
	return 0;
}
void showSeqList(SeqList L, int k) {
	if (L.length == 0) {
		printf("seqList为空\n");
	}
	if (k == 0) {
		printf("未修改的seqList = ");
	}
	else {
		printf("修改后的seqList = ");
	}
	for (int i = 1; i <= L.length; i++) {
		ElemType t;
		getSeqListElem(L, i, &t);
		printfElemType(t);
	}
	printf("\n");
}
void SeqListPartition(SeqList& L) {
	if (L.length == 0) {
		printf("seqList is empty\n");
	}
	Partition(L.data,0,L.length-1);
}
SeqList oftenUseSeqList(int k) {
//	//k=0  Type seqList have not repeate elem
//	//k=1  Type seqList have repeate elem
	SeqList L;
	ElemType *temp;
	int len;
 	initiateSeqList(&L);
	printf("oftenUseSeqList = ");
	len =getBaseDataN(k,&temp);
	for (int i = 0; i < len; i++) {
	
    	insertSeqList(&L, i + 1,temp[i+1]);
   		printfElemType(temp[i + 1]);
	}
	printf("\n");
	return L;
//
}
void InsertSortSeqList(SeqList* L) {
	InsertSort(L->data, L->length);
}
void seqListReverse(SeqList* L) {
	ElemType temp;
	for (int i = 1; i <= (L->length) / 2; i++) {
		temp = L->data[i - 1];
		L->data[i - 1] = L->data[L->length - i];
		L->data[L->length - i] = temp;
	}
}
void deleteRepeateElemInTimeNAndSpaceOne(SeqList *L,ElemType x) {
	int t = 0;
	if (L->length == 0) {

		printf("seqList is empty");
	}
	else {
		for (int i = 1; i <= L->length; i++) {
			if (IsEqual(L->data[i-1],x)) {
				t++;
			}
			else {
				L->data[i - t - 1] = L->data[i - 1];
			}
		}
		L->length -= t;
	}
}
void deleteElemInRangeConstantSToConstantT(SeqList *L, ElemType s,ElemType t) {
	/*int c = 0;
	int x;
	if (L->length == 0) {

		printf("seqList is empty\n");
	}
	else {
		if (s >= t) {
			printf("s and t have error\n");
			
		}
		else {
			for (int i = 1; i <= L->length; i++) {
				x = L->data[i - 1];
				if(x > s && x < t) {
					c++;
				}
				else {
					L->data[i - c - 1] = L->data[i - 1];
				}
			}
			L->length = L->length - c;
		}
		
	}*/
}

