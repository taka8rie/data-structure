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


//在特定位置之后添加元素（未完成）
void insertDataAt(lDoubleList alice, int position, int data){
    pDoubleNode p=alice->head->rLink;
    for (int i = 1; i < position; i++) {
        p=p->rLink;
    }
    pDoubleNode q = (pDoubleNode) malloc(sizeof(DoubleNode));
    q->info=data;
    q->rLink=p->rLink;
    q->lLink=p;
    p->rLink->lLink=q;
    p->rLink=q;
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
    for (int i = 0; i < 10; i++) {
        insertData(alice, i);
    }
    insertDataAt(alice, 8, 26);
    traverseData(alice);
    return 0;
}