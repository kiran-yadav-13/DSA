# include <iostream>
using namespace std;

// 1 2 3 4 5 5 4 3 2 1 
// 1 2 3 4 * * 4 3 2 1
// 1 2 3 * * * * 3 2 1 
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1 

// Keypoints
// step-1 carefully observe the given question and identify the no of patterns in that question.
//  for ex- in our case total 3 patterns 2 number pattern(both are same except 1st one is starting with 1 in every line and on the other hand 2nd one starting with 5(last num) )and 1 star pattern
// step 2 : if more than one pattern are at one line then these should patterns be in a common outer loop(outer while loop in our case)
// step 3 : from these pattern code the appropriate nested loops for the first printed pattern then for 2nd ,3rd and so on.
//   1st pattern :  1 2 3 4 5     2nd pattern : 5 4 3 2 1        3rd pattern:       put if condition for 1st line
//                  1 2 3 4                     4 3 2 1                       * *   (star doubles at every line)
//                  1 2 3                       3 2 1                       * * * *
//                  1 2                         2 1                       * * * * * *
//                  1                           1                       * * * * * * * *
// step 4 : try to co-relate the loop varibles of these patterns with outer loop variable and given n

void pattern1(int n){
    int i=n;
    int k;
    while(i>0){
        for(int j=1; j<=i; j++){
        cout<<j<<" ";
        }
        
        if(i<=n-1){
            for(int j=1; j<=2*(n-i); j++)
             cout<<"* ";
        }
         for(int j=i; j>0; j--){
        cout<<j<<" ";
        }
          cout<<endl;
        i--;
    }
      
   
}

int main()
{
   int n;
   cout<<"Enter the no of rows ";
   cin>>n;
   pattern1(n);
   return 0;
   }
