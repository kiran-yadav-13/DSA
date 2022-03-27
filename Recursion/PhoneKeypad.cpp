// Processesd/ Unprocessed patterns: (where exclude and include pattern can be observed )
// the processed will contain overall answer and it will contain the complete ans till unprocessed become empty .
// from unprocessed for every first charcater what possible answers can i have . these possible answers will go into different function calls
# include <iostream>
# include <vector>
# include <string>
using namespace std;
 vector<string> padRet(string p,string up){

    if(up.length()==0){
        vector<string> list;
        list.push_back(p);
     
        return list;
    }

    int digit=up[0]-'0';
    vector<string> list;

    for(int i=(digit-1)*3; i<digit*3; i++){

        char ch=(char)('a'+i);
        vector<string> ansFromBelowCalls=padRet(p+ch, up.substr(1,up.length()-1));;
        list.insert(list.end(),ansFromBelowCalls.begin(),ansFromBelowCalls.end());
        
    }
    return list;
}
void pad(string p,string up){

    if(up.length()==0){
       
        cout<<p<<"   ";
        return;
    }


    int digit=up[0]-'0';
   ;
    for(int i=(digit-1)*3; i<digit*3; i++){
        
        char ch=(char)('a'+i);
        pad(p+ch, up.substr(1,up.length()-1));
    }
}
void pad1(string p,string up,vector<string>& ans){

    if(up.length()==0){
        ans.push_back(p);
        return;
    }
    int count=0;
    int digit=up[0]-'0';
   
    for(int i=(digit-1)*3; i<digit*3; i++){
        
        char ch=(char)('a'+i);
        pad1(p+ch, up.substr(1,up.length()-1),ans);
    }
}
// counting the no of combinations

int  padcount(string p,string up){

    if(up.length()==0){
        return 1;
    }
    int count=0;
    int digit=up[0]-'0';
   
    for(int i=(digit-1)*3; i<digit*3; i++){
        
        char ch=(char)('a'+i);
        count=count+padcount(p+ch, up.substr(1,up.length()-1));
    }
    return count;
}


int main(){
  string n;
  vector<string> ans;
    cout<<"Enter the number : ";
    cin>>n;
//    ans=padRet("",n);
   pad1("",n,ans);
   cout<<" no of combinations : "<<padcount("", n)<<endl;
    cout<<"result: ";
   for(int i=0; i<ans.size(); i++){
       cout<<ans[i]<<"  ";
   }
   
    return 0;


}


