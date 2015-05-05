#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int sizeofarray;
  int a[1000];
  cin >>sizeofarray;

  for(int i = 0 ;i  <sizeofarray;i++){
    cin >>a[i];
  }
  for(int i = 1 ; i < sizeofarray;i++){
    int j = i ;
    while(j > 0 && a[j-1] > a[j]){
   int  temp = a[j];
			  a[j] = a[j-1];
			  a[j-1] = temp;
        j--;
    }
    for(int k = 0;k < sizeofarray;cout<<a[k++]<<" ");cout<<endl;
  }
    return 0;
}
