// Pallindrome : when the reversed string and the orignal string is equal 
// BruteForce approach :
// 1. Create new character array which is reverse  of the orignal array and the compare it from the orignal array 
// Second Approach :
// Take two variable start and end pointing to starting and ending position of the array and compare the value present at those indexes till s<=e
# include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for(int i=0; name[i]!='\0'; i++){
     count++;
   }
   return count;
}
char ToLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
int CheckPallindrome(char a[], int len){
    int s=0;
    int e=len-1;
    while(s<=e){
        if(ToLowerCase(a[s])!=ToLowerCase(a[e])){
        
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int main(){

   char name[20];
   int n;
   cout<<"Enter a character array : ";
   cin>>name;
   n=getLength(name);
   cout<<"Your word is pallindrome or not : "<<CheckPallindrome(name,n);
   return 0;
}