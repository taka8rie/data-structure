/*
 Created by deft on 2022/7/16.

*/
#include "iostream"
using namespace  std;

typedef struct DoubleNode * pDoubleNode;
struct DoubleNode{
    pDoubleNode lLink;
    int info;
    pDoubleNode rLink;
};
typedef struct DoubleList *lDoubleList;
struct DoubleList{
    pDoubleNode head;
    pDoubleNode rear;
};
//创建空的双链表
lDoubleList createNullDoubleList(){
    lDoubleList point = (DoubleList *) malloc(sizeof(DoubleList));
    if (point) {
        point->head=NULL;
        point->rear=NULL;
    } else{
        cout << "space not enough"<<endl;
        return NULL;
    }
    return point;
}
// 尾插法插入新的元素
// 尾插法插入新的元素
void insertData(lDoubleList point,int data){
    pDoubleNode q = (pDoubleNode) malloc(sizeof(DoubleNode));//suppose has enough space
    pDoubleNode p =NULL;
    if (point->rear == NULL) {
        point->head=q;
        point->rear=q;
        q->info=data;
        q->rLink=NULL;
        q->lLink=NULL;
    }else{
        p=point->rear;
        q->info=data;
        q->lLink=p;
        q->rLink=p->rLink;
        p->rLink=q;
        point->rear=q;
    }
}

//traverse all the elements
void traverseData(lDoubleList point){
    lDoubleList alice=point;
    if (alice) {
        if (alice->head == alice->rear) {
            cout<<alice->head->info<<" ";
        }else {
            while (alice->head != alice->rear) {
                cout << alice->head->info << " ";
                alice->head=alice->head->rLink;
            }
            cout<<alice->rear->info;
        }
    }else{
        cout << "double List is empty"<<endl;
    }
}


int main(){
    lDoubleList alice= createNullDoubleList();
    insertData(alice, 1);
    insertData(alice, 2);
    insertData(alice,3);
    traverseData(alice);
    return 0;
}