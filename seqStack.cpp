//
// Created by deft on 2022/7/24.
//
#include "iostream"
using namespace std;

struct SeqStack{
    int max;//最大容量为max
    int n;//当前栈的指针指向
    int * array;//数组名为array
};
typedef  SeqStack *PSeqStack; //PSeqStack 为指向SeqStack的指针


//创建一个容量为m的栈
PSeqStack createStack(int m){
    PSeqStack alice=new SeqStack;
    alice->array = (int *) malloc(sizeof(int) * m);// 为数组申请4m字节的空间
    if (alice->array) {
        alice->max=m;
        alice->n=-1;
        cout<<"createStack success "<<endl;
        return alice;
    }
    return NULL;
}

//数据进栈
void inStack(PSeqStack alice,int data){
    if (alice->n != alice->max) {
        alice->array[alice->n+1]=data;
        alice->n++;
    } else
        cout<<"out of stack!"<<endl;
}

//遍历栈
void traverseStack(PSeqStack alice){
    if (alice->n != -1) {
        for (int i = 0; i <= alice->n; i++) {
            cout<<alice->array[i]<<" ";
        }
    }else{
        cout<<"stack is empty "<<endl;
    }
}

//数据出栈
void popStack(PSeqStack alice){
    if (alice->n != -1) {
        cout<<alice->array[alice->n]<<" ";
        alice->n--;
    }
}

int main(){
    PSeqStack alice = createStack(10);
    for (int i = 0; i < alice->max; i++) {
        inStack(alice, i);
    }
    traverseStack(alice);
    cout<<endl;
    popStack(alice);
    cout<<endl;
    traverseStack(alice);
    cout<<endl;
    inStack(alice, 11);
    traverseStack(alice);
    return 0;
}