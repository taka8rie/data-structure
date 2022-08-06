/*
 * 此文件为使用链接表示来表达线性表的基本操作
 Created by deft on 2022/7/9.
*/
#include "iostream"
using namespace std;

//typedef struct Node *PNode;
//struct Node{
//    char info;//链表结点的信息
//    PNode next;//链表结点的指针
//};
//typedef struct Node *LinkList;

typedef struct Node{
    char info;
    struct Node * next;
}*PNode,*LinkList;

//创建一个空链表
LinkList createNullList_link(){
//   LinkList list=(Node*) malloc(sizeof(struct Node));
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
        cout << "list is null"<<endl;
        return true;
    }
    cout << "list is not null"<<endl;
    return false;
}
//确定元素x的位置
PNode LocateX(LinkList list, char x){
    PNode alice=list->next;
    if (list == NULL) {
        return NULL;
    }
    while (alice != NULL && alice->info != x) {
        alice=alice->next;
    }
    return alice;
}
//在带头结点带单链表中，在p所指的结点后，插入值为data的新结点
bool insertPost_link(LinkList list,char data) {
    PNode alice=(struct Node*)malloc(sizeof(struct Node));
    PNode p=list;
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
    PNode alice=list,temp=list;
    for (; alice->next->info != x&&alice->next!=NULL; alice = alice->next);
    temp=alice->next;
    alice->next=temp->next;alice->info=temp->info;
    temp->next=NULL;
    free(temp);
    cout<<"delete success "<<endl;
    return list;
}

int main(){
    LinkList alice= createNullList_link();
    PNode p;
    insertPost_link(alice, '1');
    insertPost_link(alice, '2');
    isNullList_link(alice);
    p = LocateX(alice, '1');
    cout<<p->info<<endl;
    delete_link(alice, '2');
    return 0;

}
