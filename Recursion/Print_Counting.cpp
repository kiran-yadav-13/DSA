# include <iostream>
using namespace std;
// Note: Before making call for some function in the body of another function . we have to first define that function whose call u are going to made
//void print5(){
//   cout<<5<<endl;
//}
//void print4(){
//   cout<<4<<endl;
//   print5();
//}
//
//void print3(){
//   cout<<3<<endl;
//   print4();
//}
//
//void print2(){
//   cout<<2<<endl;
//   print3();
//}
//
//void print1(){
//   cout<<1<<endl;
//   print2();
//}
void printReverse(int n){
    if(n<=0)
        return;
    cout<<n<<endl;
    printReverse(n-1);
}
void print(int n){
    if(n<=0)
       return;
        print(n-1);
        cout<<n<<endl;
}
int main(){
   printReverse(5);
  // print(5);
   return 0;
}
