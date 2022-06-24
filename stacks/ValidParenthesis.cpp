# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

bool isMatch(char c, char s){
    if((s=='(' && c==')') || (s=='{' && c=='}') || (s=='[' && c==']')){
        return true;
    }
    return false;
}

bool ValidParenthesis(string s){
       if((s.length()%2==1) ){
            return false;
        }
         stack<char> st;
    for(int i=0; i<s.length(); i++){
        char c=s[i];
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        else{
            // Encountered closed brackets
            // stack should not be empty for pop
            if(!st.empty()){
                if(isMatch(c,st.top())){
                    st.pop();
                }
                // there is no match found
                else{
                   return false;
                }
            }
            // Encountered closed brackets but the stack is empty 
            // Means that there is no open brackets
            else{
              return false;
            }
        }
       
    }
         if(!st.empty()){
             return false;
         }
    return true;
}
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"Parenthesis : "<<s<<endl;
    cout<<"IsValidParenthesis "<<ValidParenthesis(s)<<endl;
    return 0;
}
