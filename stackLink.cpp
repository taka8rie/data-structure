//
// Created by deft on 2022/7/24.
//
#include "iostream"
using namespace std;

struct Node{
    int info;
    Node * next;
};
typedef struct Node *PNode;
struct LinkStack{
    Node * top;
};
typedef struct LinkStack *PLinkStack;

//创建一个空链栈,
// Alice->top可不可以不需要申请空间呢？
PLinkStack createNUllLinkStack(){
    PLinkStack alice = (PLinkStack) malloc(sizeof(struct LinkStack));
    alice->top = (PNode) malloc(sizeof(struct Node));
    if (alice && alice->top) {
        alice->top->info=NULL;
        alice->top->next=NULL;
    } else{
        cout << "create fail"<<endl;
    }
    cout << "create success"<<endl;
    return alice;
}
//进栈
void pushData(PLinkStack alice,int data){
//    PNode bob=alice->top;
//    if (bob != NULL) {
//        bob->info=data;
//        bob->next=NULL;
//    }
    PNode bob=(PNode) malloc(sizeof(struct Node));
    if (alice->top) {
        bob->info=data;
        bob->next=alice->top;
        alice->top=bob;
    }
}

void traverseData(PLinkStack alice){
    if (alice) {
        PNode bob=alice->top->next;
        while (bob) {
            cout<<bob->info<<" ";
            bob=bob->next;
        }
    }
}


int main(){
    PLinkStack alice=createNUllLinkStack();
    for (int i = 0; i < 10; i++) {
        pushData(alice, i);
    }
    traverseData(alice);
    return 0;
}
