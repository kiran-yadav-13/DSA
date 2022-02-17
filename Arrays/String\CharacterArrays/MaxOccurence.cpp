# include <iostream>
using namespace std;
int CaseCheck(char s){
    if(s>='a' && s<='z'){
        int num=s-'a';
        return num;
    }
    else{
        int num=s-'A';
        return num;
    }
}
char Count(string str){

     int Letter[25]={0};
      int i=0;
       while(i<str.length()) {
         int num=CaseCheck(str[i]);
         Letter[num]=Letter[num]+1;
         i++;
     }
     i=0;
     int Ml=-1;
     int ans=-1;
     while(i<25){
         if(ans<Letter[i]){
             Ml=i;
             ans=Letter[i];
         }
      
      i++;
     }
     return Ml+'a';
}
int main(){
    string name;
   int n;
   cout<<"Enter a String : ";
   getline(cin,name);
     cout<<" string is  pallindrome: "<<Count(name);


}