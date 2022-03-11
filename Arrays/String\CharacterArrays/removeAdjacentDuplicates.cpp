# include <iostream>
using namespace std;
void removeDup(string& str){
    int i=0;
    int n=str.size();
    while(i<n){
        if(str[i]==str[i+1] ){
            str.erase(i,2);
            cout<<"str "<<str<<endl;
            if(i!=0){
                i--;
            }
        }
        else{
          i++;
        }
     n=str.size();
    }
}

// a a a a a a a a a i=0
// a a a a a a a  i=0
// a a a a a i=0
// a a a  i=0
// a i=0
//    string removeDuplicates(string s) {
//         int i=0;
//     while(i<(s.length()-1) && s.size()!=0) {
//         if(s[i]==s[i+1]){
//             s.erase(i,2);
//             // cout<<"str "<<s<<endl;
//             i=0;
//             if(s.size()==0){
//                 s="";
//             }
//         }
//         else{
//           i++;
//         }
       
//     }
//         return s;
//     }
int main(){


 string name;
   int n;
   cout<<"Enter a string : ";
   getline(cin,name);
   removeDup(name);
     cout<<" string is : "<<name;
    return 0;
}