#pragma once
#include "define.h"
typedef struct {
	int age;
	char name[10];
}Student;
void getBaseDataS(Student *s) {
	Student t = { 13,"limi" };
	*s = t;
}
int getBaseDataN(int k,Student** e) {
	Student s[5] = { {12,"liHua"},{14,"liKi"},{16,"mingGei"},{19,"liwei"},{18,"liGang"} };
	return 5;
}
void printfElemType(Student s) {
	printf("age is %d: name is %s", s.age, s.name);
}
int IsEqual(Student s,Student t) {
	if (s.name == t.name && s.age == t.age) {
		return 1;
	}
	return 0;
}
int compareElem(Student s, Student t) {
	if (IsEqual(s, t)) {
		return 0;
	}
	if (s.age > t.age) {
		return 1;
	}
	if (s.age < t.age) {
		return -1;
	}
	if (s.name < t.name) {
		return -1;
	}
	else {
		return 1;
	}
}
int IsMore(Student s, Student t) {
	if (compareElem(s, t) == 1) return 1;
	return 0;
}
int IsLess(Student s, Student t) {
	if (compareElem(s, t) == -1) return 1;
	return 0;
}