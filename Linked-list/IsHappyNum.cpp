   # include <iostream>
   using namespace std;

// ASKED IN  GOOGLE FACEBOOK

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// APPROACH:
// it is easy to solve the problem when the number is a happy number
// but when it is not a happy number then how to find or stop the llop is difficulty because in that case loop runs infinite times
// n=89
// 64+81 =145
// 1+16+25=42
// 16+4=20
// 4+0=4
// 16
// 1+36=37
// 9+49=58
// 25+64=89  // start repeating here
// hence forming the loop and we can apply the fast and slow pointer approach here 
// if there is loop present then it is not a happy number else it is a happy number


   int findSquare(int num){
    int digit=0;
    int ans=0;
    while(num>0){
        digit=num%10;
        ans=ans+digit*digit;
        num=num/10;
    }
    return ans;
   }
   
   bool IsHappyNum(int num){
       int fast=num;
       int slow=num;

       do{
        fast=findSquare(findSquare(fast));
        slow=findSquare(slow);
        if(slow==1){
            return true;
        }
       
       }while(fast!=slow);


        return false;
   }
   
   int main(){
    int n;
       cout<<"Enter a number ";
       cin>>n;
       cout<<IsHappyNum(n);
       return 0;
   }