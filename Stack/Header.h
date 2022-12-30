
#pragma once
#include <iostream>
using namespace std;
struct dmassiv {
	const static int Size = 3;
	int sizes_of_stacks[Size];
	int start[Size] = { 0,0,0 };
	int end[Size] = { 0,0,0 };
	int* massiv;
};
void add(int, int, dmassiv*);
void print(int, dmassiv*);
void pop(int, dmassiv*);
bool is_full(int, dmassiv*);
int lenth(int, dmassiv*);
void alloc(dmassiv*);
void del(dmassiv*);
bool is_empty(int, dmassiv*);