//
// Created by Henry on 2020-08-26.
//

#include "ac.h"

#define InitSize 10

typedef struct {
    int *data;
    int MaxSize;
    int length;

}SeqList;


void InitList(SeqList &L) {
    L.data = (int *) malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc(sizeof(int) * (L.MaxSize + len));
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
int main () {
    SeqList L;
    InitList(L);
    IncreaseSize(L, 10);

    return 0;
}

