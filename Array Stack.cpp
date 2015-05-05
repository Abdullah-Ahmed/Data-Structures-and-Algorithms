#include <iostream>
using namespace std;
typedef struct{
    int top;
    int stk[1000];
}stack;
void intialization(stack *s){s->top = 0;}
bool isempty(stack *s){return s->top == 0;}
bool isfull(stack *s){return s->top == 1000;}
int pop(stack *s){return s->stk[--s->top];}
void push(stack*s,int value){
    if(!isfull(s))
        s->stk[s->top++] = value;
    }
int main(){
stack s;
intialization(&s);
for(int i = 0 ; i <= 10 ; i++)push(&s,i);
while(!isempty(&s)){
    cout<<pop(&s)<<" ";
}
    return 0;
}
