#pragma once
#include "ElemType.h"
typedef struct SqStack {
	ElemType data[StackMaxSize];
	int top;
} SqStack;
void initiate(SqStack& st) {
	st.top = -1;
}
int isEmpty(SqStack st) {
	return st.top == -1;
}
int push(SqStack& st, int x) {
	if (st.top == StackMaxSize) return 0;
	st.data[++st.top] = x;
	return 1;
}
int pop(SqStack& st, int& x) {
	if (st.top == -1) return 0;
	x = st.data[st.top--];
	return 1;
}
int get(SqStack& st, int& x) {
	if (st.top == -1) return 0;
	x = st.data[st.top];
	return 1;
}
int simpleStackWrite() {
	int stack[StackMaxSize]; 
	int top = -1; 
	ElemType x;
	stack[++top] = x; // 一句话实现进栈
	x = stack[top--]; // 一句话实现
	return 0;
}
