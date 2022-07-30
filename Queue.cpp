//
// Created by deft on 2022/7/28.
//
#include "iostream"
using namespace  std;

struct SeqQueue{
    int max;
    int head,tail;
    int *data;
};
typedef struct SeqQueue * PSeqQueue;

//initial SeqQueue
PSeqQueue createNullSeqQueue (int max){
    PSeqQueue alice=new SeqQueue;
    alice->max=max;
    alice->head=0;
    alice->tail=0;
    alice->data=(int *) malloc(sizeof(int)*max);//calculate each "int" value ,multiple by m;
    return alice;
}

bool isEmptyQueue(PSeqQueue alice){//头指针为将要删除，尾指针为将要增加
    if ((alice->tail+1)%alice->max==alice->head) {
        cout<<"queue is full"<<endl;
        return false;
    } else if (alice->head == alice->tail) {
        cout << "queue is empty";
        return true;
    }
}

void traverseData(PSeqQueue alice){
    if (!isEmptyQueue(alice)) {
        for (int i = alice->head; i != alice->tail; i++) {
            cout<<alice->data[i]<<" ";
        }
    } else
        cout<<"Queue is empty! "<<endl;
}

void enQueue(PSeqQueue alice,int info){
    if ((alice->tail + 1) % alice->max == alice->head) {
        cout<<"Queue is full "<<endl;
    }else{
        alice->data[alice->tail]=info;
        alice->tail=(alice->tail+1)%alice->max;
    }
}

int main(){
    PSeqQueue alice= createNullSeqQueue(5);
    for(int i=0;i<4;i++){
        enQueue(alice, i);
    }
    traverseData(alice);
}