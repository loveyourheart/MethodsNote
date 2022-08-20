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
	// ���ҵ���Ԫ��
	LNode* p;
	p = list;
	while (p->next != NULL) {
		if (IsEqual(p->next->data, x)) {
			break;
		}
		p = p->next;
	}
	// Ȼ��ɾ��
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
				r = q;//ѡ����Сֵ
			q = q->next;
	}
	return r;
}
void findMinAndDelete(LinkList &L) {
	LNode* r,*q;
	printf("��Сֵ = ");
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
	LNode* s; // s����ָ��������Ľڵ�
	s = (LNode*)malloc(sizeof(LNode));
	LinkList r = getTrailPointer(L);
	s->data = x;
	s->next =NULL;
	r->next = s;
}
void insertlistF(LinkList& L, ElemType x) {
	LNode* s; // s����ָ��������Ľڵ�
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
	// ���ڲ��ܸı���A, B�Լ������ݣ����Ե��趨p, q�����в���
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* r,*s; // rʼ��ָ��C���ն˽ڵ�
	C = A; // ��A��ͷ���������C��ͷ���
	C->next = NULL;
	free(B);
	r = C; // ���Ե�ʱ��CҲ���ն˽ڵ�
	while (p != NULL && q != NULL) {
		s = (LNode*)malloc(sizeof(LNode));
		if (IsLess(p->data,q->data)) {
			s->data = p->data;
			s->next = NULL;
			r->next = s; // �õ�ǰ���ն˽ڵ�ָ���µ��ն˽ڵ�
			p = p->next; // p��ȻҪ����Ųһ��
			r = r->next; // ����r��ָ����rָ���µ��ն˽ڵ�
		}
		else {
			s->data = q->data;
			s->next = NULL;
			r->next = s;
			q = q->next;
			r = r->next;
		}
	}
	// p����ʣ��
	while (p != NULL) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = p->data;
		s->next = NULL;
		r->next = s;
		p = p->next;
		r = r->next;
	}
	// q����ʣ��
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
			// ��������ֳ�s��������
			// ���û��s��
			// ��ֱ��p->next = C->next,
			// ��ô�ı���p��ָ��p�޷�������Ų��
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
	// ����ͷ�壬�����������ѭ����ÿ��ʣ��Ԫ�طŵ�����C��ǰ��ȥ
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
	int i, count = 0, num;//count��¼������ĸ�����num�����ڲ�ѭ����
	LNode* p, * q, * tail;//��������ָ�룬����ð������
	p = L;
	while (p->next != NULL)//��������ĸ���
	{
		count++;//ע�͢�
		p = p->next;
	}
	for (i = 0; i < count - 1; i++)//���ѭ����������ð������һ��
	{
		num = count - i - 1;//��¼�ڲ�ѭ����Ҫ�Ĵ�����������ð������һ����
		q = L->next;//��qָ���һ�����
		p = q->next;//��pָ���һ�����
		tail = L;//��tailʼ��ָ��qǰһ����㣬���㽻����Ҳ�����������һ������
		while (num--)//�ڲ�ѭ�� ����������ð������һ��
		{
			if (q->data > p->data)//����ý���ֵ���ں�һ����㣬�򽻻�
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;//ע�͢�
			q = tail->next;//ע�͢�
			p = q->next;//ע�͢�
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
				r = q;//ѡ����Сֵ
			q = q->next;
		}
		if (r != p)
		{
			s = r->next;
			r->next = s->next;//����ѭ������Сֵ������ɾ��

			s->next = p->next;
			p->next = s;//����ѭ������Сֵ��������
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