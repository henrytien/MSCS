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

// 顺序表的定义
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

// 顺序表的插入
bool ListInsert(SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (i >= L.MaxSize)
        return false;
    for (int j = L.length; j >= i; --j) {
        L.data[j-1] = L.data[j];
    }
    L.data[i-1] = e;
    L.length++;
}

// 顺序表的删除操作
bool ListDelete(SeqList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    for (int j = i; j < L.length; ++j) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

// 顺序表的按值查找，返回位序
int LocateItem(SeqList &L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

void PrintList(const SeqList &L) {
    for (int i = 0; i < L.length; ++i) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 综合应用题第5题
bool Del_s_t(SeqList &L, int s, int t) {
    int k = 0;
    if (L.length == 0 || s >= t) {
        return false;
    }

    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s && L.data[i] <= t) {
            k++;
        } else {
            L.data[i-k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}


int main () {
    SeqList L;
    InitList(L);
    IncreaseSize(L, 10);

    for (int i = 0; i < 10; ++i) {
        ListInsert(L, i+1, i);
    }

    PrintList(L);

    Del_s_t(L, 3, 8);

    PrintList(L);



    return 0;
}

