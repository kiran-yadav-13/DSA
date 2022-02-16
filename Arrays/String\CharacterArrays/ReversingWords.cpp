// 557. Reverse Words in a String III
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// Example 1:
// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
# include <iostream>
# include <string>
using namespace std;
void swap(char &temp1, char &temp2){
     char temp=temp1;
     temp1=temp2;
     temp2=temp;
 }

string ReverseWords(string s){
    int start=0;
    int end=start;
    while(end<=s.length()-1){
        
        if(s[start]==' '){
            
            s.erase(start,1);
        }
      else if(s[end]!=' ' && end!=s.length()-1){
          end++;
      }
      else{
    if(end==s.length()-1){
        end++;
    }
    int e=end-1;
     while(start<=e){

        swap(s[start], s[e]);
      
            start++;
            e--;
            
    }
    start=end+1;
    end=start;

       }
    }
   return s;
    
}
int main(){
   string name;
   int n;
   cout<<"Enter a character array : ";
   getline(cin,name);
     cout<<" string is  pallindrome: "<<ReverseWords(name);
    // name.erase(1,1);
    // cout<<name;
   return 0;
}
