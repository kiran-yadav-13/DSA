// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
# include <iostream>
# include <string>
using namespace std;
bool valid(char s){
    if((s>='a' && s<='z') ||  (s>='0' && s<='9') || (s>='A' && s=<'Z')){
      return true;
}
return false;
}
char ToLowerCase(char s){
    if((s>='a' && s<='z') || (s>='0' && s<='9')){
       return s;
    }
    else{
        char temp=s-'A'+'a';
         return temp;
    }
  
}
bool ValidPallindrome(string str){
   int s=0;
   int e=str.length()-1;
   while(s<=e){
       
       if(valid(str[s])==false){
         s++;
       }
       else if(valid(str[e])==false){
         e--;
       }
       else if(ToLowerCase(str[s])!=ToLowerCase(str[e])){
           return false;
       }
       else{
           s++;
           e--;
       }
   }
   return true;
}


int main(){

   string name;
   int n;
   cout<<"Enter a character array : ";
   getline(cin,name);
    cout<<" string is  pallindrome: "<<ValidPallindrome(name);
   return 0;
}