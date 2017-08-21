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
void PrintTree(AvlTree T);

static int Height(Position P);
static int Max(int a, int b);
static Position SingleRotateWithLeft(Position);
static Position SingleRotateWithRight(Position);
static Position DoubleRotateWithLeft(Position);
static Position DoubleRotateWithRight(Position);