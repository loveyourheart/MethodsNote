#pragma once
#include <math.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Staus;

#define SeqListMaxSize 100 //顺序表的最大长度

#define  MAX_SIZE  100  
#define  SWAP(x,y,t)  ((t) = (x),(x) = (y),(y) = (t)) 
#define  MAX_TERMS  101  
#define  MAX_POLYS  15   
#define  MAX_STACK_SIZE 100   
#define  MAX_QUEUE_SIZE 100  
#define  MEMORY_SIZE 100 
#define  MAX_STACKS 10     
#define  MAX_QUEUES 10    
#define  IS_EMPTY(first) (!(first))  
#define  IS_FULL(temp) (!(temp))  

#define  MAX_ELEMENTS 200  
#define  HEAP_FULL(n) (n == MAX_ELEMENTS - 1) 
#define  HEAP_EMPTY(n) (!n)   
#define  MAX_VERTICES  50   

//浮点数的大小比较
const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)-(b)))<(eps))
#define More(a,b) (((a)-(b))>(eps))
#define Less(a,b) (((a)-(b))<(eps))
#define MoreEqu(a,b) (((a)-(b))>(-eps))
#define LessEqu(a,b) (((a)-(b))<(eps))

//线性表define
