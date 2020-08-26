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

int main() {
    SeqList L;
    L.data = (int*)malloc(sizeof(int)*InitSize);
    cout << "hello world!" <<endl;
    return 0;
}

```

