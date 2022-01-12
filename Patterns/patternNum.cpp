# include <iostream>
using namespace std;
// Pattern1 : print the following pattern
//   1
//   1 2
//   1 2 3
//   1 2 3 4
//   1 2 3 4 5
void pattern1(int n){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
           cout<<col<<" ";
        }
        cout<<endl;
    }
}
//       1 1 1 1 1 1
//       2 2 2 2 2
//       3 3 3 3
//       4 4 4
//       5 5
//       6

// Pattern2 : print the following pattern
void pattern2(int n){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=n-row+1; col++){
           cout<<row<<" ";
        }
        cout<<endl;
    }
}

//  3.    1
//        2  3
//        4  5  6
//        7  8  9  10
//        11 12 13 14 15
void pattern3(int n){
    int count=0;
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
            count++;
           cout<<count<<" ";
        }
        cout<<endl;
    }
}
// 4 .      1
//         212
//        32123
//       4321234
//        32123
//         212
//          1
void pattern4(int n){
    int count=0;
    for(int row=1; row<=2*n-1; row++){
        count=row;
        int s=row<=n?n-row:row-n;
        for(int space=1; space<=s; space++){
            cout<<" ";
        }
        for(int col=1; col<=2*row-1; col++){
            if(col<row){
                cout<<count;
                count--;
            }
            else{
              
              cout<<count<<" ";
               count++;
            }
           
        }
        cout<<endl;
    }
}


//  5.         1
//           2 1 2
//         3 2 1 2 3
//       4 3 2 1 2 3 4
//     5 4 3 2 1 2 3 4 5
void pattern5(int n){
    int count=0;
    for(int row=1; row<=n; row++){
        count=row;
        for(int space=1; space<=n-row; space++){
            cout<<"  ";
        }
        for(int col=1; col<=2*row-1; col++){
            if(col<row){
                cout<<count<<" ";
                count--;
            }
            else{
             cout<<count<<" ";
               count++;
            }
           
        }
        cout<<endl;
    }
}
    //    E D C B A
    //    D C B A
    //    C B A
    //    B A
    //    A
    void pattern6(int n){
        char ch=65;
    for(int row=1; row<=n; row++){
        ch=65+(n-row);
        for(int col=1; col<=n-row+1; col++){
           cout<<ch<<" ";
           ch--;
        }
        cout<<endl;
    }
    }
    //    E
    //    D E
    //    C D E
    //    B C D E
    //    A B C D E
  void pattern7(int n){
        char ch=65;
    for(int row=1; row<=n; row++){
        ch=65+(n-row);
        for(int col=1; col<=row; col++){
           cout<<ch<<" ";
           ch++;
        }
        cout<<endl;
    }
    }
//  8.    1      1
//        12    21
//        123  321
//        12344321
void pattern8(int n){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
           cout<<col;
        }
        for(int space=1; space<=2*(n-row); space++)
        {
            cout<<" ";
        }
        for(int col=row; col>=1; col--){
           cout<<col;
        }
        cout<<endl;
}
}
int main()
{
   int n;
   cout<<"Enter the no of rows : ";
   cin>>n;
   //pattern1(n);
  // pattern2(n);
 // pattern3(n);
 //pattern5(n);
 //pattern4(n);
 //pattern6(n);
 //pattern7(n);
 pattern8(n);
   return 0;
}
