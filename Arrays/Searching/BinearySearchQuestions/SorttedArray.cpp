# include <iostream>
# include <vector>
using namespace std;
vector<int> BinearySearch(int a[][10],int row, int cStart,int cEnd, int target ){
    vector<int> ans;
    while(cStart<=cEnd){
        int mid=cStart+(cEnd-cStart)/2;
        if(a[row][mid]==target){
            ans.push_back(row);
            ans.push_back(mid);
            return ans;
        }
        if(a[row][mid]<target){
            cStart=mid+1;
        }
        else{
            cEnd=mid-1;
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
vector<int> Search(int a[][10], int row, int col, int target){
   vector<int> ans;
    if(col==0){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    if(row==1){
        return BinearySearch(a,0,0,col-1,target);
    }
    int rowStart=0;
    int rEnd=row-1;
    int cMid=col/2;

    // run bthe loop till two rows are remaining
    while(rowStart<(rEnd-1)){ // while this is true it will have more than two rows

        int mid=rowStart+(rEnd-rowStart)/2;
        if(a[mid][cMid]==target){
         ans.push_back(mid);
         ans.push_back(cMid);
         return ans;
        }
        if(a[mid][cMid]<target){
            rowStart=mid;
        }
        else{
            rEnd=mid;
        }
    }
    // now we have two rows
    // check whether the target is in the col of 2 rows
    // check whether the target is in the middle row
    if(a[rowStart][cMid]==target){
        ans.push_back(rowStart);
         ans.push_back(cMid);
         return ans;
    }
    if(a[rowStart+1][cMid]==target){
        ans.push_back(rowStart+1);
         ans.push_back(cMid);
         return ans;
    }
    // 4 parts
    //1st part
    if(target<=a[rowStart][cMid-1]){
        return BinearySearch(a,rowStart,0,cMid-1,target);
    }
    //2nd part
    if(target>=a[rowStart][cMid+1] && target<=a[rowStart][col-1]){
        return BinearySearch(a,rowStart,cMid+1, col-1,target);
    }
    //3rd part
    if(target<=a[rowStart+1][cMid-1]){
        return BinearySearch(a, rowStart+1,0,cMid-1,target);
    }
    else{
        return BinearySearch(a,rowStart+1,cMid+1,col-1,target);
    }
}
int main()
{
 vector<int> dim;
int row,col,target;
cout<<"Enter the no of rows in an array : ";
cin>>row;
cout<<"Enter the no of columns in an array : ";
cin>>col;
int a[10][10];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        cin>>a[i][j];
    } 
}
cout<<"Enter the target element : ";
cin>>target;
dim=Search(a,row,col,target);
for(int i:dim){
    cout<<i<<" ";
}
return 0;
}