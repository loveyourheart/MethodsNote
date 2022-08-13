#pragma once
#include<stdio.h>
#include"linkList.h"
void initLinkListTest() {
	LinkList L;
	LNode* s,*t;
	LNode *p;
	initLinkList(L);
	createlistR(L, intnum, 12);
	printfLinkListElem(L);
	s = getTrailPointer(L);
	t = find(L, 2);
	s->next = t;
	if (IsHaveCycle(L, p)) {
		//printfLNode(p);
		printf("%d  ",p->data);
	}
}   
