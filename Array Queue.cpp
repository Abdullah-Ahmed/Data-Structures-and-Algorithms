#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct {
    int head,tail;
    int sizes;
    int noofelements;
    int *queu;
}queue;
void intialization(queue *q,int sizes){
q->head = 0;
q->tail = 0;
q->sizes = sizes;
q->noofelements = 0;
q->queu = (int*)malloc(q->sizes*sizeof(int));
}
void enqueue(queue *q,int value){
q->queu[q->tail++] = value;
q->tail%=q->sizes;
q->noofelements++;
}
int dequeue(queue *q){
q->noofelements --;
q->head%=q->sizes;
return q->queu[q->head++];
}
bool isfull(queue *q){return q->tail ==q->sizes;}
bool isempty(queue *q) {return q->noofelements==0; return q->head == q->tail;}
int main(){
queue *q;
intialization(q,10);
for(int i  = 1 ; i <= 10 ; i++) enqueue(q,i);
while(!isempty(q)) cout<<dequeue(q)<<" ";cout<<endl;
    return 0;
}
