// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
     int tour(petrolPump p[],int n)
    {
      
        int defecit=0; // store how much petrol is required to complete the previous requirement
       int balance=0;  // balanced petrol left after travelling the distance
       int start=0;

     
       for(int i=0; i<n; i++)
    {
       
        balance=balance+p[i].petrol-p[i].distance;
        if(balance<0){
           defecit+=balance;
           start=i+1;   // since fom start to i it cannnot be traversed then it further cannnot be traversed by the middle petrol pumps 
           balance=0;
            
        }

       }

       if(balance+defecit<0){
        return -1;
       }

       return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends
