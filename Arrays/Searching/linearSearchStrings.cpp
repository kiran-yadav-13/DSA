# include <iostream>
using namespace std;

// Return boolean value
bool LinearSearchString(string str, char target){
     if(str.length()==0){
         return false;
     }
     for(int i=0; i<str.length(); i++){
         if(str.at(i)==target){
             return true;
         }
     }
     return false;
 }
 int main(){
char target;
string str;
cout<<"Enter the string : ";
cin>>str;
cout<<"Enter the character element to be searched : ";
cin>>target;
cout<<LinearSearchString(str,target);

return 0;
}
