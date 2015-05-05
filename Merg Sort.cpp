#include <iostream>
using namespace std;
int mergy(int a[],int start1,int ends1,int start2,int ends2);
 void mergesort(int a[],int start,int ends){
 if(start < ends){
    int mid = (start+ends)/2;
    mergesort(a,start,mid);
    mergesort(a,mid+1,ends);
    mergy(a,start,mid,mid+1,ends);
 }
 }

int mergy(int a[] , int start1,int ends1,int start2,int ends2){
int k = 0 , i = start1 , j = start2;
int tempo[100000];
while(i <= ends1 && j <= ends2){
    if(a[i] > a[j]){
        tempo[k++] = a[j++];
    }
    else {
        tempo[k++] = a[i++];
    }
}
while(i<=ends1) tempo[k++] = a[i++];
 while(j<=ends2) tempo[k++] = a[j++];
for(int x = 0 , g = start1;x < k ; g++,x++)
    a[g] = tempo[x];
}
int main(){
int n;
cin >>n;
int a[1000];
for(int i = 0 ; i < n ;i++) cin>>a[i];

mergesort(a,0,n);

for(int i =0 ; i < n ;i++) cout<<a[i]<<" ";cout<<endl;
    return 0;
}

