# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

  void reverseString(vector<char>& s) {
       if(s.size()==0){
            return;
        }
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
        }
        for(int i=0; i<s.size(); i++){
           s[i]=st.top();
           st.pop();
        }
    }

    // Two pointers appraoch

    void Reverse(vector<char>& s ){
        if(s.size()==0){
            return;
        }
        int i=0;
        int j=s.size()-1;
        char temp;
        while(i!=j){
     
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
           
        }

    }

int main(){
    vector<char> s;
    int n;
    char a;
    cout<<"Enter the length : ";
    cin>>n;
     for(int i=0; i<n; i++){
        cin>>a;
            s.push_back(a);
        }
    //   reverseString(s);
    Reverse(s);
    cout<<"Reversed String : ";
        for(int i=0; i<s.size(); i++){
           cout<<s[i]<<"  ";
        }
}
