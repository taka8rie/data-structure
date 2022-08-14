//
// Created by deft on 2022/8/14.
//
#include "iostream"
using namespace std;

typedef struct SeqString{
    int max;
    int n;
    char *c;
}*PSeqString;

PSeqString createNullStr_seq(int m){
    PSeqString alice = (PSeqString) malloc(sizeof(SeqString));
    if (alice) {
//        cout<<"create success"<<endl;
        alice->max=m;
//        alice->c=(char *) malloc(sizeof(char*m));sizeof的使用问题
        alice->c=(char *) malloc(sizeof(char)*m);
        if (alice->c) {
            alice->n=0;
        } else{
            free(alice->c);
        }
    }else{
        free(alice);
    }
    return alice;
}

PSeqString cinString(PSeqString &carol){
    int i;
    for ( i = 0; i < carol->max; i++) {
        cin>>carol->c[i];
    }
    carol->n=i;
    return carol;
}

void traverseString(PSeqString carol){
    for (int i = 0; i < carol->n; i++) {
        cout<<carol->c[i]<<" ";
    }
    cout<<endl;
}

int index(PSeqString alice, PSeqString bob){
    int i=0,j=0;
    while (i < alice->n && j < bob->n) {
        if (alice->c[i] == bob->c[j]) {
            i++;
            j++;
        } else{
            i=i-j+1;
            j=0;
        }
    }
    return i-bob->n+1;
}

int main(){
    int flag;
    PSeqString alice = createNullStr_seq(6);
    PSeqString bob = createNullStr_seq(3);
    cinString(alice);
    cinString(bob);
    traverseString(alice);
    traverseString(bob);
    flag = index(alice, bob);
    cout<<"flag is "<<flag;
    return 0;
}