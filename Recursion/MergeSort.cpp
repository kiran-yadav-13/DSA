# include <iostream>
using namespace std;
void input(int a[], int n){
    int i;
    for(i=0; i<n; i++){
       cin>>a[i];
    }
}
void display(int a[], int n){
     for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
      }
      cout<<endl;
}

void Merge(int a[], int s, int m, int e){
    int n1=m-s+1;
    int n2=e-m;
    int L[200], R[200];
    for(int i=0; i<n1; i++){
        L[i]=a[s+i];
    }
    cout<<"Left Array : "<<endl;
    display(L,n1);
    for(int j=0; j<n2; j++){
        R[j]=a[m+j+1];
    }
     cout<<"rIGHT Array : "<<endl;
    display(R,n2);
    L[n1+1]=INT_MAX;
    R[n2+1]=INT_MAX;
    int i,j=0;
    for(int k=s; k<e; k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
    else{
        a[k]=R[j];
        j++;
    }
    }

}
void Merge_Sort(int a[], int s, int e){
    if(s<e){
        int mid =s+(e-s)/2;
        Merge_Sort(a,s,mid);
        Merge_Sort(a,mid+1,e);
        Merge(a,s,mid,e);
    }
}

int main(){
    int n;
    int a[100];
    cout<<"Enter the no of elements in an array : ";
    cin>>n;
    input(a,n);
    Merge_Sort(a,0,n-1);
    display(a,n);
    return 0;
}
