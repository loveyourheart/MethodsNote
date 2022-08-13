#pragma once
#include<stdio.h>
#include"SeqList.h"
int num[10] = { 2,1,3,4,6,5,7,8,0,9 };
void initiateSeqListTest() {
	SeqList L;
	initiateSeqList(&L);

	printf("answer = %d",L.length);

}
void insertSeqListTest() {
//	SeqList L;
//	initiateSeqList(&L);
//	insertSeqList(&L, 1, 2);
//	printf("insert answer = %d", L.data[0]);
}
void deleteSeqListTest() {
//	SeqList L;
//	ElemType a;
//	initiateSeqList(&L);
//	insertSeqList(&L, 1, 2);
//	insertSeqList(&L, 1, 4);
//	deleteSeqList(&L, 2, &a);
//	printf("delete answer =  %d", L.data[1]);
}
// 

void LocateElemTest() {
//	SeqList L;
//	initiateSeqList(&L);
//	for (int i = 0; i < 10; i++) {
//		insertSeqList(&L, 1, num[i]);
//	}
//	int r = LocationElem(L, 3);
//	ElemType t;
//	getSeqListElem(L, r, &t);
//	printf("answer = %d  value=", r);
//	printfElemType(t);
}
void deleteSeqListMinValueTest() {
	SeqList L = oftenUseSeqList(0);
	int t;
	ElemType minvalue,temp1;
	printf("原表  = ");
	for (int i = 1; i <= L.length; i++) {
		ElemType t;
		getSeqListElem(L, i, &t);
		printfElemType(t);
	}
	printf("\n");
	deleteSeqListMinValue(&L, &minvalue,&t);
	deleteSeqList(&L, L.length, &temp1);
	insertSeqList(&L, t, temp1);
	printf("修改后表  = ");
	for (int i = 1; i <= L.length; i++) {
		ElemType t;
		getSeqListElem(L, i, &t);
		printfElemType(t);
	}
	printf("\n");

}
void deleteSeqListMaxValueTest() {
	SeqList L = oftenUseSeqList(0);
	int t;
	ElemType minvalue, temp1;
	printf("原表  = ");
	for (int i = 1; i <= L.length; i++) {
		ElemType t;
		getSeqListElem(L, i, &t);
		printfElemType(t);
	}
	printf("\n");
	deleteSeqListMaxValue(&L, &minvalue, &t);
	printf("修改后表  = ");
	for (int i = 1; i <= L.length; i++) {
		ElemType t;
		getSeqListElem(L, i, &t);
		printfElemType(t);
	}
	printf("\n");
}
void seqListReverseTest() {
	SeqList L = oftenUseSeqList(1);
	showSeqList(L, 0);
	seqListReverse(&L);
	showSeqList(L, 1);
}
void deleteRepeateElemInTimeNAndSpaceOneTest() {
//	SeqList L=oftenUseSeqList(1);
//	showSeqList(L,0);
//	deleteRepeateElemInTimeNAndSpaceOne(&L, 4);
//	showSeqList(L, 1);
}
void deleteElemInRangeConstantSToConstantTTest() {
//	SeqList L = oftenUseSeqList(1);
//	showSeqList(L, 0);
//	ElemType s = 3;
//	ElemType t = 8;
//    deleteElemInRangeConstantSToConstantT(&L,s,t);
//	showSeqList(L, 1);
//	
}
void sortSeqListTest() {
  /*  SeqList L = oftenUseSeqList(1);
	showSeqList(L, 0);
	sortSeqList(&L);
	showSeqList(L,1);*/
}
void StudentTest() {
	/*SeqList L;
	initiateSeqList(&L);
	ElemType t;
	Student s = {12,"qwer"};
	insertSeqList(&L, 1, s);
	showSeqList(L, 0);
	getSeqListElem(L, 1, &t);
	printfElemType(t);*/
}
void deleteRangeTest(){
	/*SeqList L=oftenUseSeqList(0);
	deleteRange(L, 1, 3);
	showSeqList(L, 1);*/
}
void partitionTest() {
	/*SeqList L = oftenUseSeqList(0);
	SeqListPartition(L);
	showSeqList(L, 1);*/
}