# include <iostream>
using namespace std;
// pattern2 : print the following pattern
//  *
//  **
//  ***
//  ****
//  *****
void pattern2(int n){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
            cout<<"* ";
        }
        cout<<endl;
    }

}
// pattern3 : print the following pattern
//    *****
//    ****
//    ***
//    **
//    *
void pattern3(int n){
  for(int row=1; row<=n ;row++){
      for(int col=1; col<=n-row+1; col++){
          cout<<"* ";
      }
      cout<<endl;
  }

}
// pattern4 : print the following pattern
//  1   *
//  2   **
//  3   ***
//  4   ****
//  5   *****
//  6   ****
//  7   ***
//  8   **
//  9   *
// Keypoints:
// 0 Total rows 2n-1
// 1 Note that upto certain row the no of columns=no of columns
// 2. when the no of col start changing . find no of stars we have to discrad at each row from n
// i.e row-n in this case  ex- for  row 8 col=8-5=3(non prinatble stars from Total n stars)
// Printable stars = n-(row-1)
void pattern4(int n){
   for(int row=1; row<=(2*n-1); row++){
        int c= row>n?(2*n-row):row;
       for(int col=1; col<=c; col++)
       {
           cout<<"* ";
       }
       cout<<endl;
   }
}
int main(){
int n;
   cout<<"Enter the no of rows ";
   cin>>n;
   //pattern2(n);
  // pattern3(n);
  pattern4(n);
    return 0;

}
