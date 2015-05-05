#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node{
int value;
 node* next;
};
typedef struct linkedlist{
    node *head,*tail;
};

void initialization(linkedlist* l){
l->head = l->tail = NULL;
}

bool isempty(linkedlist *l){
return l->head;
}

node* newnode(int value){
node *n =(node*) malloc(sizeof(node));
n->value = value;
n->next = NULL;
}

void addnodetolist(linkedlist *l,int value){
node *n = newnode(value);
//cout<<"*"<<value<<" "<<l->head<<endl;
n->next = l->head;
    l->head = n;
if(!l->tail)
l ->tail = n;
}

void addnodetotail(linkedlist *l,int value){
node *n = newnode(value);
node *tailcheck = l->tail;
//cout<<"**"<<value<<" "<<l->tail<<endl;
l->tail = n;
if(tailcheck) tailcheck->next = n;
else l->head->next = n;
}

void printlist(node *n){
    while(n) {
            cout<<n->value<<" "<<n->next<<endl;
    n =(node*) n->next;
    }
}
int main(){
linkedlist *l;
l = (linkedlist*) malloc(sizeof(linkedlist));
initialization(l);
for(int i = 1 ; i <=10;i++){
//cout<<"*"<<i<<endl;
        if(i%2)
 addnodetolist(l,i);
else addnodetotail(l,i);
}
cout<<"**"<<l->head<<endl;
printlist(l->head);
cout<<"**"<<l->head<<endl;
    return 0;
}
