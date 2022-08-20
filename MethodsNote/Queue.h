#pragma once
#include "ElemType.h"
typedef struct {
	ElemType data[QueueMaxSize];
	int front; // ����ָ��
	int rear; // ��βָ��
}SqQueue;
void initiate(SqQueue& qu) {
	qu.front = qu.rear = 0; // ���׺Ͷ�βָ���غϣ�����ָ��0
}
int isEmpty(SqQueue qu) {
	return qu.front == qu.rear; // ֻҪ�غϣ���Ϊ�ն�
}
int push(SqQueue& qu, int x) {
	if ((qu.rear + 1) % QueueMaxSize == qu.front) return 0; // �����������
	qu.rear = (qu.rear + 1) % QueueMaxSize; // ��δ���������ƶ�ָ��
	qu.data[qu.rear] = x; // �ٷ���Ԫ��
	return 1;
}
int pop(SqQueue& qu, int& x) {
	if (qu.front == qu.rear) return 0; // ���ӿգ�����ɾ��
	qu.front = (qu.front + 1) % QueueMaxSize; // ���Ӳ��գ������ƶ�ָ��
	x = qu.data[qu.front]; // ��ȡ��Ԫ��
	return 1;
}