# include <iostream>
# include <vector>
using namespace std;
vector<string> diceReturn(string p, int target){
    
    if(target==0){
        vector<string> list;
        list.push_back(p);
        return list;
    }
      vector<string> list;
        
    for(int i=1; i<=6 && i<=target; i++){
       vector<string> fromBelow= diceReturn(p+to_string(i), target-i);
       list.insert(list.end(),fromBelow.begin(),fromBelow.end());
    }
   return list;
}
vector<string> diceReturnface(string p,int& face, int target){
    
    if(target==0){
        vector<string> list;
        list.push_back(p);
        return list;
    }
      vector<string> list;
        
    for(int i=1;  i<=face && i<=target; i++){
       vector<string> fromBelow= diceReturnface(p+to_string(i),face, target-i);
       list.insert(list.end(),fromBelow.begin(),fromBelow.end());
    }
   return list;
}

void dice(string p, int target){
    
    if(target==0){
        cout<<p<<"  ";
        return;
    }
    for(int i=1; i<=6 && i<=target; i++){
        dice(p+to_string(i), target-i);
    }
}
int main(){
  int n,face;
  vector<string> ans;
    cout<<"Enter the number : ";
    cin>>n;
     cout<<"Enter the number of faces in a dice : ";
    cin>>face;
    cout<<"result: ";
   // dice("",n);
      ans=diceReturnface("", face,n);
      for(int i=0; i<ans.size(); i++){
       cout<<ans[i]<<"  ";
   }
   return 0;
}