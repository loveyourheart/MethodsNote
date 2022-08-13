#pragma once
#include"ElemType.h"
typedef struct StackLNode {
	ElemType data;
	struct StackLNode* next;
}StackLNode, * StackList;
void initiate(StackList & lst) {
	lst = (StackLNode*)malloc(sizeof(StackLNode));
	lst->next = NULL; // 还是老规矩：申请新的节点后一定要为其指针域设置为空
}
int isEmpty(StackList lst) {
	return lst->next == NULL;
}
void push(StackList &lst, int x) {
	// 步骤一：申请新的节点，存放x的值
	// 步骤二：头插法将新的节点插入链栈中
	StackLNode* p = (StackLNode*)malloc(sizeof(StackLNode));
	p->next = NULL;
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}
int pop(StackList &lst, int& x) {
	// 步骤一：判空
	// 步骤二：删除节点
	if (lst->next == NULL) return 0;
	x = lst->data;
	StackLNode* p;
	p = lst->next;
	lst->next = lst->next->next;
	free(p);
	return 1;
}
int get(StackList& lst, int& x) {
	// 步骤一：判空
	// 步骤二：删除节点
	if (lst->next == NULL) return 0;
	x = lst->data;
	return 1;
}
