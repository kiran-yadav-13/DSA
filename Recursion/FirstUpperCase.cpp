// # include <bits/stdc++.h>
# include <iostream>
# include <string>

using namespace std;
char UpperCase(string str, int i){
    
  
    if(i==str.length()-1){
        return '0';
    }
    if(str[i]>=65 && str[i]<=90 ){
        return str[i];
    }
    
    return UpperCase(str, i+1);
}
int main(){
string str;
char r;
cout<<"Enter string : ";
cin>>str;
 r=UpperCase(str,0);
 cout<<" Result "<<r<<endl;
 return 0;
}