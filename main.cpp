#include <iostream>
#include "vector"
using namespace std;

struct SeqList{
    int maxmum;
    int n;//存放线性表中元素的个数，n<=MAXNUM
    int *element;
};
typedef SeqList * PSeqList;

PSeqList createNullList_seq(int m){
    PSeqList palist = (PSeqList) malloc(sizeof(struct SeqList));
    if (palist != NULL) {
        palist->element =(int *) malloc(sizeof(int) * m);
        if (palist->element != NULL) {
            palist->maxmum=m;
            palist->n=0;
            return palist;
        } else free(palist);
    }
    cout << "out of space!\n";
    return NULL;
}

int isNullList_seq(PSeqList pSeqList){//为空返回1，不为空返回0
    return (pSeqList->n == 0);
}

int locate_seq(PSeqList pSeqList, int x){
    //在pSeqList中寻找x,有则返回下标，否则返回-1
    for (int i = 0; i < pSeqList->n; i++) {
        if (x == pSeqList->element[i]) {
            return i;
        }
    }
    return -1;
}

int insertPre_seq(PSeqList pSeqList,int data,int p){
    if (p < 0 || p > pSeqList->maxmum) {
        cout<<"插入失败"<<endl;
        return 0;
    }

    if (pSeqList->n <= pSeqList->maxmum - 1) {
        for (int i = pSeqList->n - 1; i >=p; i--) {
            pSeqList->element[i+1]=pSeqList->element[i];
        }
        pSeqList->element[p]=data;
        pSeqList->n=pSeqList->n + 1;
        return 0;
    }
    return 1;
}

int deleteP_seq(PSeqList pSeqList, int p){
    if (p < 0 || p > pSeqList->n-1) {
        cout<<"this position is not exist"<<endl;
        return 0;
    }
    for (int i = p; i < pSeqList->n-1; i++) {
        pSeqList->element[p] = pSeqList->element[p + 1];
    }
    pSeqList->n=pSeqList->n-1;
    return 1;
}

void showP_seq(PSeqList pSeqList){
    for (int i = 0; i < pSeqList->n; i++) {
        cout<<pSeqList->element[i]<<" ";
    }
}

int main(){
    PSeqList bang = createNullList_seq(10);
    int number= isNullList_seq(bang);
    cout<<"is NULL ? 1:0 "<<number<<endl;
    for (int i = bang->maxmum; i >=0; i--) {
        insertPre_seq(bang, i, bang->maxmum-i);
    }
    showP_seq(bang);
    cout<<endl;
    int findx = locate_seq(bang, 8);
    cout<<"find "<<findx<<endl;
    return 0;
}
