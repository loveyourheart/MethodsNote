#pragma once
#include"ElemType.h"
typedef struct StackLNode {
	ElemType data;
	struct StackLNode* next;
}StackLNode, * StackList;
void initiate(StackList & lst) {
	lst = (StackLNode*)malloc(sizeof(StackLNode));
	lst->next = NULL; // �����Ϲ�أ������µĽڵ��һ��ҪΪ��ָ��������Ϊ��
}
int isEmpty(StackList lst) {
	return lst->next == NULL;
}
void push(StackList &lst, int x) {
	// ����һ�������µĽڵ㣬���x��ֵ
	// �������ͷ�巨���µĽڵ������ջ��
	StackLNode* p = (StackLNode*)malloc(sizeof(StackLNode));
	p->next = NULL;
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}
int pop(StackList &lst, int& x) {
	// ����һ���п�
	// �������ɾ���ڵ�
	if (lst->next == NULL) return 0;
	x = lst->data;
	StackLNode* p;
	p = lst->next;
	lst->next = lst->next->next;
	free(p);
	return 1;
}
int get(StackList& lst, int& x) {
	// ����һ���п�
	// �������ɾ���ڵ�
	if (lst->next == NULL) return 0;
	x = lst->data;
	return 1;
}
