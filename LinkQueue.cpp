//
// Created by deft on 2022/8/6.
//
#include "iostream"
using namespace std;

struct Node{
    int value;
    Node * next;
};
typedef struct Node * PNode;

struct LPoint{
    Node * head;
    Node * tail;
};
typedef struct LPoint *PLPoint;

//create initial LinkNode;
PLPoint createNullLinkNode(){
    PLPoint LinkPoint = (PLPoint) malloc(sizeof(LPoint));
//    PNode alice = (PNode) malloc(sizeof(Node));
//    if (!alice) {
//        cout << "space not enough"<<endl;
//        return NULL;
//    }
//    alice->value=NULL;
//    alice->next=NULL;
//    LinkPoint->head=alice;
//    LinkPoint->tail=alice;
    LinkPoint->head=NULL;
    LinkPoint->tail=NULL;
    return LinkPoint;
}
//insert from bottom,using PLPoint's reference
bool insertValue(PLPoint &alice,int info){
    PNode bob = (PNode) malloc(sizeof(Node));
    if (!bob) {
        cout << "insert new value fail";
        return false;
    }
//    bob->value=info;
//    bob->next=NULL;
//
//    alice->tail->next=bob;
//    alice->tail=bob;

    bob->value=info;
    bob->next=NULL;
    if (alice->head==NULL && alice->tail == NULL) {
        alice->head=bob;
        alice->tail=bob;
    }else{
        alice->tail->next=bob;
        alice->tail=bob;
    }

    return true;
}

void traverseData(PLPoint alice){
    if (!alice) {
        cout << "LinkQueue empty"<<endl;
    }
    PNode bob=alice->head;
    for (; bob != alice->tail; bob = bob->next) {
        cout<<bob->value<<" ";
    }
}
// 如果在创建空链的时候，创建了一个空的Node，那么该结点会自动赋值0？
//struct test{
//    int a;
//};
//typedef struct test *carlos;
//
//void  output(carlos alice){
//    cout<<alice->a;
//}

int main(){
    PLPoint alice = createNullLinkNode();
    for (int i = 0; i < 10; i++) {
        insertValue(alice, i);
    }
    traverseData(alice);
    cout<<endl;
//    carlos bob = (carlos) malloc(sizeof(test));
//    output(bob);
    return 0;
}