#pragma once
#include "ElemType.h"
#include<assert.h>
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
void initLinkList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}
int len(LinkList &L,LNode *p) {
	LinkList r = L;
	int len=0;
	while (r->next != NULL) {
		len++;
		if (p == r->next) break;
		r = r->next;
	}
	return len;
}
LinkList getTrailPointer(LinkList &L) {
	LinkList r=L;
	while (r->next != NULL) r = r->next;
	return  r;

}
LinkList find(LinkList &L, int pos) {
	LNode* r = L;
	int i = 1;
	if (pos == 0) return L;
	if (pos < 1) {
		printf("pos is error");
		return 0;
	}
	while (r!=NULL&&i <= pos) {
		r = r->next;
		i++;
	}
	return r;
}
void getOddPointer(LinkList &L) {

}
int findAndDelet(LNode* list, ElemType x) {
	// 先找到该元素
	LNode* p;
	p = list;
	while (p->next != NULL) {
		if (IsEqual(p->next->data, x)) {
			break;
		}
		p = p->next;
	}
	// 然后删除
	if (p->next == NULL) {
		return 0;
	}
	else {
		LNode* del;
		del = p->next;
		p->next = p->next->next;
		free(del);
		return 1;
	}
}
LinkList findMinElem(LinkList &L) {
	LNode* p, * q, * r, * s;
	p = L;
	q = p->next;
	r = p;
	while (q->next != NULL)
	{
			if (IsLess(q->next->data, r->next->data))
				r = q;//选出最小值
			q = q->next;
	}
	return r;
}
void findMinAndDelete(LinkList &L) {
	LNode* r,*q;
	printf("最小值 = ");
	while(L->next!=NULL){
		r = findMinElem(L);
		printfElemType(r->next->data);
		q = r->next;
		r->next = q->next;
		free(q);
	}
	printf("\n");
}
void insertlistR(LinkList& L, ElemType x) {
	LNode* s; // s用来指向新申请的节点
	s = (LNode*)malloc(sizeof(LNode));
	LinkList r = getTrailPointer(L);
	s->data = x;
	s->next =NULL;
	r->next = s;
}
void insertlistF(LinkList& L, ElemType x) {
	LNode* s; // s用来指向新申请的节点
	s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	s->next = L->next;
	L->next = s;

}
void insertlistF(LinkList& L, LNode *s) {
	s->next = L->next;
	L->next = s;

}
void createlistR(LinkList  &L,ElemType a[], int n) {
	LNode *s,* r=getTrailPointer(L);
	for (int i = 0; i < n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	
}
void createlistF(LinkList &L, ElemType a[], int n) {
	for (int i = 0; i < n; i++) insertlistF(L, a[i]);

}
int deleteElem(LinkList &L,int pos) {
	if (pos < 1) return 0;
	LinkList t = find(L, pos - 1);
	LNode* s;
	s = t->next;
	t->next = s->next;
	if (s != NULL) {
		free(s);
		return 1;
	}
	return 0;
}
int deleteElem(LinkList& L, int s, int t) {
	LinkList r = find(L, s - 1);
	LinkList q;
	if (s<1 || s>t) return 0;
	int len = t - s + 1;
	while (r->next != NULL && len != 0) {
		q = r->next;
		r->next = q->next;
		free(q);
		len--;
	}
	return 1;
}
int clear(LinkList& L) {
	deleteElem(L, 1, len(L, NULL));

	return 0;
}
int isEmpty(LinkList &L) {
	if (L->next == NULL) return 1;
	return 0;
}
void printfLNode(LNode* node) {
	printfElemType(node->data);
}
void printfLinkListElem(LinkList list) {
	LinkList temp=list;
	printf("Linklist = ");
	while (temp->next!=NULL) {
		printfElemType(temp->next->data);
		temp = temp->next;
	}
	printf("\n");
}
void mergeR(LinkList &A, LinkList& B, LinkList & C) {
	// 由于不能改变了A, B自己的内容，所以得设定p, q来进行操作
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* r,*s; // r始终指向C的终端节点
	C = A; // 将A的头结点用来做C的头结点
	C->next = NULL;
	free(B);
	r = C; // 初试的时候C也是终端节点
	while (p != NULL && q != NULL) {
		s = (LNode*)malloc(sizeof(LNode));
		if (IsLess(p->data,q->data)) {
			s->data = p->data;
			s->next = NULL;
			r->next = s; // 让当前的终端节点指向新的终端节点
			p = p->next; // p自然要往后挪一步
			r = r->next; // 更新r的指向，让r指向新的终端节点
		}
		else {
			s->data = q->data;
			s->next = NULL;
			r->next = s;
			q = q->next;
			r = r->next;
		}
	}
	// p还有剩余
	while (p != NULL) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = p->data;
		s->next = NULL;
		r->next = s;
		p = p->next;
		r = r->next;
	}
	// q还有剩余
	while(q != NULL) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = q->data;
		s->next = NULL;
		r->next = s;
		q = q->next;
		r = r->next;
	}
}
void mergeF(LNode* A, LNode* B, LNode*& C) {
	LNode* p = A->next;
    LNode * q = B->next;
	LNode* s;
	C = A;
	C->next = NULL;
	free(B);
	while (p != NULL && q != NULL) {
		if (IsLess(p->data, q->data)||IsEqual(p->data,q->data)) {
			// 这里就体现出s的作用了
			// 如果没有s，
			// 则直接p->next = C->next,
			// 那么改变了p的指向，p无法再往后挪了
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		}
		else {
			s = q;
			q = q->next;
			q->next = C->next;
			C->next = s;
		}
	}
	// 由于头插，所以这里必须循环将每个剩余元素放到链表C的前面去
	while (p != NULL) {
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL) {
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
}
int linkListBecomeArrays(LinkList& L, ElemType A[]) {
	LinkList r = L;
	int len = 0;
	while (r->next != NULL) {
		A[len++] = r->next->data;
		r = r->next;
	}
	return len;
}
void bubbleSort(LinkList& L)
{
	int i, count = 0, num;//count记录链表结点的个数，num进行内层循环，
	LNode* p, * q, * tail;//创建三个指针，进行冒泡排序
	p = L;
	while (p->next != NULL)//计算出结点的个数
	{
		count++;//注释①
		p = p->next;
	}
	for (i = 0; i < count - 1; i++)//外层循环，跟数组冒泡排序一样
	{
		num = count - i - 1;//记录内层循环需要的次数，跟数组冒泡排序一样，
		q = L->next;//令q指向第一个结点
		p = q->next;//令p指向后一个结点
		tail = L;//让tail始终指向q前一个结点，方便交换，也方便与进行下一步操作
		while (num--)//内层循环 次数跟数组冒泡排序一样
		{
			if (q->data > p->data)//如果该结点的值大于后一个结点，则交换
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//注释②
			q = tail->next;//注释②
			p = q->next;//注释②
		}
	}
}
void selectSort(LinkList &L)
{

	LNode* p, * q, * r, * s;
	p = L;
	while (p->next != NULL)
	{
		q = p->next;
		r = p;
		while (q->next != NULL)
		{
			if (IsLess(q->next->data,r->next->data))
				r = q;//选出最小值
			q = q->next;
		}
		if (r != p)
		{
			s = r->next;
			r->next = s->next;//将本循环的最小值从链表删除

			s->next = p->next;
			p->next = s;//将本循环的最小值插入链表
		}
		p = p->next;
	}
}
void partition(LinkList& L,int k) {
	ElemType num[20];
	int len=linkListBecomeArrays(L, num);
	clear(L);
	Partition(num, k - 1, len - 1);
	createlistR(L, num, len);
}
void spliteABLinkListByParity(LinkList &A, LinkList &B) {
	//according to parity to splite LinkList
	initLinkList(B);
	LNode* rA,*rB,*HA,*temp;
	HA = A;
	rA = A->next;
	rB = B;
	while (rA != NULL&&rA->next!=NULL) {
		temp= rA->next;
		rA->next = temp->next;
		rA = rA->next;
		temp->next = NULL;
		rB->next = temp;
		rB = rB->next;
	}
}
void spliteByParityABLinkBisInsertF(LinkList& A, LinkList& B) {
	//according to parity to splite LinkList
	initLinkList(B);
	LNode* rA, * rB, * HA, * temp;
	HA = A;
	rA = A->next;
	rB = B;
	while (rA != NULL && rA->next != NULL) {
		temp = rA->next;
		rA->next = temp->next;
		rA = rA->next;
		insertlistF(B, temp);
	}
}
int IsHaveCycle(LinkList &L,LinkList &s) {
	LNode* p, * q,*r;
	p = L;
	q = L->next;
	s = L;
	int t = 0;
	while (q!=NULL&&q->next != NULL && q != p) {
		p = p->next;
		q = q->next->next;
	}
	if (q == p) {
		while (1) {
			r = p->next;
			if (r == p) {
				s = r;
			}
			while (r != p) {
				if (s == r) {
					t = 1;
					break;
				}
				r = r->next;
			}
			if (t == 1) {
				break;
			}
			s = s->next;
		}
		return 1;
	}
	return 0;
}