# include <iostream>
using namespace std;
// pattern1 : print the following pattern
// 1.       *
//         **
//        ***
//       ****
//      *****
//Keypoints:
// space are n-rows
// rows=n
// columns in a col=row
void pattern1(int n){
     for(int row=1; row<=n; row++){
         for(int space=1; space<=n-row; space++){
             cout<<"  ";
         }
         for(int col=1; col<=row; col++){
             cout<<"* ";
         }
         cout<<endl;
     }
}
// pattern2: print the following pattern
//  2.  *****
//       ****
//        ***
//         **
//          *
// KeyPoints:
// at every line space=row-1
// col=n-rows-1

void pattern2(int n){
   for(int row=1; row<=n; row++){
         for(int space=1; space<=row-1; space++){
             cout<<"  ";
         }
         for(int col=1; col<=n-row+1; col++){
             cout<<"* ";
         }
         cout<<endl;
   }
     }
// pattern3: print the following pattern
//3.      *
//       ***
//      *****
//     *******
//    *********
//keypoints:
//no of cols in each row is 2row-1
//space is first 5, 4,3,2,1 so space in each row is n-row
void pattern3(int n){
   for(int row=1; row<=n; row++){
         for(int space=1; space<=n-row; space++){
             cout<<"  ";
         }
         for(int col=1; col<=2*row-1; col++){
             cout<<"* ";
         }
         cout<<endl;
   }
     }
// pattern4 : print the following pattern
//    *********
//     *******
//      *****
//       ***
//        *
void pattern4(int n){
   for(int row=1; row<=n; row++){
         for(int space=1; space<=row-1; space++){
             cout<<"  ";
         }
         for(int col=1; col<=2*(n-row)+1; col++){
             cout<<"* ";
         }
         cout<<endl;
   }
     }
// pattern5 : print the following pattern
//5.      *
//       ***
//      *****
//     *******
//    *********
//     *******
//      *****
//       ***
//        *

void pattern5(int n){
   for(int row=1; row<=2*n-1; row++){
       int s=row<=n?n-row:row-1;
       int c=row<=n? 2*row-1:2*(n-row)+1;
         for( int space=1; space<=s; space++){
             cout<<"  ";
         }
         for(int col=1; col<=c; col++){
             cout<<"* ";
         }
         cout<<endl;
   }
     }
    // 10.  *
    //     * *
    //    * * *
    //   * * * *
    //  * * * * *
    void pattern7(int n){
      for(int row=1; row<=n; row++){
         for(int space=1; space<=n-row; space++){
             cout<<"  ";
         }
         for(int col=1; col<=row; col++){
             cout<<" * ";
         }
         cout<<endl;
   }
    }

//      * * * * *
//       * * * *
//        * * *
//         * *
//          *
//          *
//         * *
//        * * *
//       * * * *
//      * * * * *
void pattern6(int n){
    for(int row=1; row<=2*n; row++){
       int s=row<=n?row-1:2*n-row;
       int c=row<=n? n-row+1:row-n;
         for( int space=1; space<=s; space++){
             cout<<"  ";
         }
          for(int col=1; col<=c; col++){
             cout<<" * ";
         }
         cout<<endl;
    }
}

// .    * * * * *
//       * * * *
//        * * *
//         * *
//          *
void pattern8(int n){
     for(int row=1; row<=n; row++){
         for(int space=1; space<=row-1; space++){
             cout<<"  ";
         }
         for(int col=1; col<=n-row+1; col++){
             cout<<" * ";
         }
         cout<<endl;
   }
}
    //      *
    //     * *
    //    *   *
    //   *     *
    //  *       *
    //   *     *
    //    *   *
    //     * *
    //      *
void pattern9(int n){
    for(int row=1; row<=2*n-1; row++){
       int s=row<=n?n-row:row-n;
       int c=row<=n? row:2*n-row;
         for( int space=1; space<=s; space++){
             cout<<"  ";
         }
          for(int col=1; col<=c; col++){
              if (col==1 || col==c)
              {
                  cout<<" * ";
              }
              else{
                  cout<<"   ";
              }
            
         }
         cout<<endl;
    }
}
//          *
//         * *
//        *   *
//       *     *
//      *********

void pattern10(int n){
     for(int row=1; row<=n; row++){
         for(int space=1; space<=n-row; space++){
             cout<<"  ";
         }
         for(int col=1; col<=row; col++){
             if(row==n){
                cout<<"**";
             }
             else if(col==1 || col==row)
             cout<<"* ";
             else
             cout<<"  ";
         }
         cout<<endl;
   }
}
// 11.       *****
//          *   *
//         *   *
//        *   *
//       *****
void pattern11(int n){
     for(int row=1; row<=n; row++){
         for(int space=1; space<=n-row; space++){
             cout<<"  ";
         }
         for(int col=1; col<=n; col++){
             if(row==1 || row==n)
              cout<<"*";
              else{
                  if(col==1 || col==n){
                      cout<<"*";
                  }
                  else{
                      cout<<" ";
                  }
              }
         }
         cout<<endl;
     }
}
    //    *        *
    //    **      **
    //    ***    ***
    //    ****  ****
    //    **********
    //    ****  ****
    //    ***    ***
    //    **      **
    //    *        *
    void pattern12(int n){
       for(int row=1; row<=2*n-1; row++){
       int c=row<n?row:2*n-row;
       for(int col=1; col<=c; col++)
       {
           cout<<"*";
       }
       int s=row<=n?2*(n-row):2*(row-n);
       for(int space=1; space<=s; space++)
        {
            cout<<" ";
        }
       for(int col=1; col<=c; col++)
       {
           cout<<"*";
       }
       cout<<endl;
   }
    }
int main()
{
   int n;
   cout<<"Enter the no of rows ";
   cin>>n;
  // pattern1(n);
  //pattern2(n);
 // pattern3(n);
 //pattern4(n);
 //pattern5(n);
// pattern6(n);
// pattern7(n);
//pattern8(n);
//pattern9(n);
//pattern10(n);
//pattern11(n);
pattern12(n);
   return 0;
}
