#pragma once
#include<stdio.h>
#include<malloc.h>
#include "SeqList.h"
#include "ElemType.h"
//typedef struct {
//	ElemType* elem;
//	int TableLen;
//}SSTable;
//int Search_Seq(SSTable ST, ElemType key) {
//	ST.elem[0] = key;
//	int i;
//	for (i = ST.TableLen; ST.elem[i] != key; --i);
//	return i;
//}
//void Search_SeqTest() {
//	SSTable st;
//	int TableLenMax = 100,n,temp,key;
//	st.elem = (ElemType*)malloc(TableLenMax * sizeof(ElemType));
//	st.TableLen = 0;
//	printf("输入查找数组的长度n:");
//	scanf("%d", &n);
//	printf("输入数组A,以空格分隔数据，如2 3 4: ");
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &temp);
//		st.elem[i] = temp;
//		st.TableLen = st.TableLen + 1;
//		printf("%d ", st.elem[i]);
//	}
//	printf("\n输入查找数:");
//	scanf("%d", &key);
//	temp = Search_Seq(st, key);
//	printf("数是A[%d]=%d",temp,st.elem[temp]);
//
//}
//int Binary_Search() {
//	SeqList seq;
//	initiateSeqList(&seq);
//	return 0;
//}