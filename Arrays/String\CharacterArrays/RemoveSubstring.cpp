# include <iostream>
# include <string>
using namespace std;
string RemoveSubstring(string str, string sub){
//     int i=0;
//     int found=str.find(sub);
//    while(found<=(str.length()-1) && found>-1){
//        found=str.find(sub);
//     if(found<=(str.length()-1)){
//            str.erase(found,sub.length());
//        }
//    }
while(str.length()!=0 && str.find(sub)<str.length()){
    str.erase(str.find(sub),sub.length());
}
  return str;
}
int main(){
    string name,sub;
   int n;
   cout<<"Enter a String : ";
   getline(cin,name);
   cout<<"Enter the substring : ";
   cin>>sub;
     cout<<" string after removal of substring: "<<RemoveSubstring(name,sub);


}
