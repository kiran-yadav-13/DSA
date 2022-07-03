# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;


bool findRedundantBrackets(string &s)
{
  
  if(s.length()%2==1){
  }
  stack<char> st;

   for(int i=0; i<s.length(); i++){
    char ch=s[i];
    cout<<"ch "<<ch<<endl;
      if(ch=='(' || ch=='{' || ch=='[' || ch=='+' || ch=='-' || ch=='*' || ch=='%' || ch=='/'){
            st.push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']'){
            // closed brackets found 
            bool isRedundant=true;
            char temp=st.top();
            
           
              
                while(!(temp=='(' || temp=='{' || temp=='[' )  ){
                     temp=st.top();
                     if( temp=='+' || temp=='-' || temp=='*' || temp=='%' || temp=='/'){
                         isRedundant=false;
                     }
                    
                    st.pop();
                }
                
                    
                   
            if(isRedundant==true){
                return true;
            }
            
             st.pop();

            }
           
          
        }
   
   return false;
}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"Parenthesis : "<<s<<endl;
    cout<<"IsValidParenthesis "<<findRedundantBrackets(s)<<endl;
    return 0;
}
