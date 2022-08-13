#pragma once
#include "ElemType.h"

typedef char VertexType;
typedef int  EdgeType;
typedef struct {
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;
typedef struct ArcNode{
	int adjvex;
	struct ArcNode* next;

}ArcNode;
typedef struct VNode {
	VertexType data;
	ArcNode* first;

}VNode,AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;

}ALGraph;



