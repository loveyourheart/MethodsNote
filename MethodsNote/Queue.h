#pragma once
#include "ElemType.h"
typedef struct {
	ElemType data[QueueMaxSize];
	int front; // 队首指针
	int rear; // 队尾指针
}SqQueue;
void initiate(SqQueue& qu) {
	qu.front = qu.rear = 0; // 队首和队尾指针重合，并且指向0
}
int isEmpty(SqQueue qu) {
	return qu.front == qu.rear; // 只要重合，即为空队
}
int push(SqQueue& qu, int x) {
	if ((qu.rear + 1) % QueueMaxSize == qu.front) return 0; // 队满则不能入队
	qu.rear = (qu.rear + 1) % QueueMaxSize; // 若未满，则先移动指针
	qu.data[qu.rear] = x; // 再放入元素
	return 1;
}
int pop(SqQueue& qu, int& x) {
	if (qu.front == qu.rear) return 0; // 若队空，则不能删除
	qu.front = (qu.front + 1) % QueueMaxSize; // 若队不空，则先移动指针
	x = qu.data[qu.front]; // 再取出元素
	return 1;
}