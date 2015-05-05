#include <iostream>
using namespace std;
void quicksort(int a[],int start,int ends){
int L = start;
int R = ends;
//cout<<"(1)\n";for(int i = start ; i < ends;i++) cout<<a[i]<<" ";cout<<endl;
int mid = (L+R)/2;
int pivot = a[mid];
while(a[L]<pivot)L++;
while(a[R]>pivot)R--;

if(L<=R) {
swap(a[L],a[R]);
L++;
R--;
}
//cout<<"(2)\n";for(int i = start ; i < ends;i++) cout<<a[i]<<" ";cout<<endl;
if(start < R)
    quicksort(a,start,R);
if(L < ends)
    quicksort(a,L,ends);
}
int main(){
int n;
cin >> n ;
int a[1000];
for(int i = 0 ; i < n ;i++) cin >>a[i];
quicksort(a,0,n);
for(int i = 0 ; i < n ;i++) cout<<a[i]<<" ";cout<<endl;
    return 0;
}
