/*
 * 此文件为使用链接表示来表达线性表的基本操作
 Created by deft on 2022/7/9.
*/
#include "iostream"
using namespace std;

typedef struct Node *PNode;
struct Node{
    char info;//链表结点的信息
    PNode next;//链表结点的指针
};
typedef struct Node *LinkList;

LinkList createNullList_link(){
   //LinkList list=(Node*) malloc(sizeof(struct Node));
   Node *list=new Node;
    if (list == NULL) {
        cout << "space not enough"<<endl;
    }else{
        list->next=NULL;
    }
    return list;
}

bool isNullList_link(LinkList list){
    if (list->next == NULL) {
        return false;
    }
    return true;
}

PNode LocateX(LinkList list, char x){
    PNode temp;
    for (temp->next = list->next->next,temp->info=list->next->info;
        temp->next != NULL; temp->next = temp->next->next) {
        if (temp->info == x) {
            return temp;
        }
    }
    return NULL;
}

bool insertPost_link(LinkList list, PNode p,char data){//在带头结点带单链表中，插入值为data的新结点


}

int main(){
    cout<<"abc";
    return 0;
}
