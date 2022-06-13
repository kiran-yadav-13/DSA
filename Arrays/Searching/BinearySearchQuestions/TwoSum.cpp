# include <iostream>
# include <vector>
using namespace std;

// binary serach;
vector<int> twoSum2(int a[], int n, int target){
     int pair1=0;
     int pair2=0;
   
    vector<int> ans={-1,-1};
    while(pair1<n-1){
          
     int start=pair1+1;
     int end=n;

     while(start<=end){
          int pair2=start+(end-start)/2;
          if((a[pair1]+a[pair2])==target){
            ans[0]=pair1;
            ans[1]=pair2;
            return ans;
          }
          else if((a[pair1]+a[pair2])<target){
            start=pair2+1;
          }
          else{
            end=pair2-1;
          }

    }

    pair1++;

    }
    return ans;

}


vector<int> twoSum(int a[], int n, int target){
    int start=0;
    int end=n-1;
    vector<int> ans={-1,-1};
   while(start<end){
       if((a[start]+a[end])==target){
           ans[0]=start;
           ans[1]=end;
           return ans;
       }
       else if((a[start]+a[end])<target){
           start++;
       }
       else{
           end--;
       }
    //    cout<<(a[start]+a[end])<<endl;
    }
    return ans;
}
int main(){
int a[30], n,target;
vector<int>ans;

cout<<"Enter the no of integer you want ";
cin>>n; 
cout<<"enter the numbers : ";
for(int i=0; i<n ; i++){
    cin>>a[i];
}
cout<<"Enter the no of target sum  ";
cin>>target;
ans=twoSum(a, n , target);

for(int i=0; i<ans.size() ; i++){
    cout<<ans[i]<<" ";
}
return 0;
}