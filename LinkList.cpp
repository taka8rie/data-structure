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

//创建一个空链表
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
//判断链表是否为空
bool isNullList_link(LinkList list){
    if (list->next == NULL) {
        return false;
    }
    return true;
}
//确定元素x的位置
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
//在带头结点带单链表中，在p所指的结点后，插入值为data的新结点
bool insertPost_link(PNode p, char data) {
    PNode alice=(struct Node*)malloc(sizeof(struct Node));
    if (alice == NULL) {
        return false;
    }
    alice->info=data;
    alice->next=p->next;
    p->next=alice;
    return true;
}

//在单链表中求p所指结点的前驱结点
PNode findPre(LinkList list, PNode p){
    PNode alice=list;
    for (; alice->next != p; alice = alice->next) ;
    return alice;
}

//删除第一个元素为x的结点，返回成功与否的标志
bool delete_link(LinkList list,char x){
    PNode alice=list;
    for (; alice->info != x; alice = alice->next);
}

int main(){
    cout<<"abc";
    return 0;
}
