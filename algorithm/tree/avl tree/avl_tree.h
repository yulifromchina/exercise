#pragma once
#include <iostream>
#include <cassert>
#include <queue>

struct AvlNode;
using Position = struct AvlNode *;
using AvlTree = struct AvlNode *;
using ElementType = int;

AvlTree Insert(ElementType x, AvlTree T);
AvlTree Delete(ElementType x, AvlTree T);
Position FindPrecursor(Position T);
Position FindSuccessor(Position T);
void Free(AvlTree T);
bool IsAvl(AvlTree T);
void IsAvlTree(AvlTree T);

void PrintTree(AvlTree T);

static int Height(Position P);
static int Max(int a, int b);
static Position SingleRotateR(Position);
static Position SingleRotateL(Position);
static Position DoubleRotateLR(Position);
static Position DoubleRotateRL(Position);