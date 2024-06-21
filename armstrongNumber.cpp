//ArmstrongNumber - the number in which the sum of the cube of thedigits is same as the number itself
// n= 371 = 3^3+7^3+1^3 =371

# include <bits/stdc++.h>
using namespace std;

int armstrongNum(int n ){
    int temp=n;
    int armstrong=0;
    while(temp>0){
        int digit=temp%10;
        armstrong=armstrong+(digit*digit*digit);
        temp=temp/10;
    }
    if(armstrong==n){
        return true;
    }
    return false;
}
int main(){
 int n;
 cout<<"Enter the number "<<endl;
 cin>>n;
 cout<<"number is armstrong "<<armstrongNum(n)<<endl;
 return 0;
}
