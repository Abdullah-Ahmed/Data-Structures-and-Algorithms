#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct node{
int value;
node *left,*right;
};

node*newnode(int value){
node*nwnode = new node; //The same  (node*)malloc(sizeof(node))
nwnode->value = value;
nwnode->left = nwnode->right = NULL;
return nwnode;
}

node*insert(node*root,int value){
node *nwnode = newnode(value);
if(root){
    if(root->value > value){
        if(!root->left){
            root->left = nwnode;
        }else{
        insert(root->left,value);
        }
    }else{
        if(!root->right){
            root->right = nwnode;
        }else{
        insert(root->right,value);
        }
 }
}
return nwnode;
}
node*search(node*root,int value){
    if(!root) return NULL;
if(root->value == value){
    return root;
}
if(root->value > value){
    search(root->left,value);
}
else search(root->right,value);
}

int noofnodes(node*root){
    if(!root) return 0;
  return 1+noofnodes(root->left)+noofnodes(root->right);
}

int depth(node*root){
if(!root) return 0;
return  max(1+depth(root->left),1+depth(root->right));
}
void dfs(node*root){
if(!root) return;
cout<<root->value<<" ";
dfs(root->left);
dfs(root->right);
}

void bfs(node*root){
queue<node*>q;
q.push(root);
while(!q.empty()){
    node*n = q.front();q.pop();
    cout<<n->value<<" ";
    if(n->left)
    q.push(n->left);
if(n->right)
    q.push(n->right);
}
}
int main(){
  node *searchTree=NULL;
    searchTree=insert(searchTree,10);
    insert(searchTree,4);insert(searchTree,16);insert(searchTree,3);
    insert(searchTree,12);insert(searchTree,5);insert(searchTree,100);insert(searchTree,13);

    printf("Max Level=%d\n",depth(searchTree));
    if (search(searchTree,13)) printf("13 found\n");else printf("13 not found\n");
    if (search(searchTree,17)) printf("17 found\n");else printf("17 not found\n");
dfs(searchTree);cout<<endl;
    bfs(searchTree);cout<<endl;
    return 0;
}
