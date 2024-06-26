#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void print(){
    if(cnt==3){
        return;
    }
    cout<<cnt<<endl;
    cnt++;
    print();
}


 void printName(int i,int n){
    if(i>n) return;
    cout<<"Kiran"<<endl;
    printName(i+1,n);

 }

 void printCnt(int i, int n){
    if(i>n)   return;
    cout<<i<<endl;
    i++;
    printCnt(i,n);
    return;
 }

void reverseNum(int i, int n){
    if(i<1){
        return;
    }
    cout<<i<<endl;
    reverseNum(i-1,n);

}


// print  1to n without using i+1 and by backtracking
// - backtracking is doing or performing any function after the return of recursion call

void printCntBckTrk(int i, int n){
    if(i<1){
        return;
    }

    printCntBckTrk(i-1, n);
    cout<<i<<endl;
} 

// printing n to 1 without i-1
void printCntBackTrack(int i, int n){
    if(i>n){
        return;
    }

    printCntBackTrack(i+1, n);
    cout<<i<<endl;
}
int main(){
    // print();
    // printName(1,3);
    // printCnt(1,5);
    // reverseNum(5,5);
    // printCntBckTrk(5,5);
    printCntBackTrack(1,5);
    return 0;
}