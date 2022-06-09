# include <iostream>
# include <vector>
using namespace std;


int helper(int num[],int n, int target, bool findstartindex){
    int ans=-1;
    int start=0;
    int end=n;
    while(start<=end){
       int mid=start+(end-start)/2;
        if(num[mid]<target){
            start=mid+1;
        }
        else if(num[mid]>target){
            end=mid-1;
        } // potential ans found
        else{
            ans=mid;
             if(findstartindex){
                 // there could be more target element in the left hand side
                 end=mid-1;
             }
             else{
                  // there could be more target element in the right hand side
                  start=mid+1;
             }
        }
    }
    return ans;
}

vector<int> searchRange(int num[], int n, int target){
    vector<int> ans={-1, -1};
int start=helper(num, n, target,true);
int end=helper(num, n, target,false);

ans[0]=start;
ans[1]=end;
return ans;
}
int main(){
   
   int n;
 vector<int>ans;
int target;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Enter target elements of an array : ";
cin>>target;
ans=searchRange(a, n, target);
cout<<"starting and ending index of the target element: ";
for(int i=0; i<ans.size(); i++){
  cout<<ans[i]<<endl;
}


return 0;
}