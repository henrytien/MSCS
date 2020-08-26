# 数据结构

## 第一章 绪论

## 第二章 线性表

###  顺序表的定义

```c++
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

int main() {
    SeqList L;
    InitList(L);
    cout << "hello world!" <<endl;
    return 0;
}

```

### 顺序表的插入

```c++
// 线性表的插入
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
```



### 顺序表的删除操作

```c++
bool ListDelete(SeqList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    for (int j = i; j < L.length; ++j) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
```

### 顺序表的查找

```c++
int LocateItem(SeqList &L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}
```

