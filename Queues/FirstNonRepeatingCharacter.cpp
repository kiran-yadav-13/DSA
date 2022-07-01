// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
			string FirstNonRepeating(string A){
		  
      if(A.length()<=1){
        return A;
      }

          // store the count
          queue<char> q;
          unordered_map<char, int>count;
           char ch;
           string ans="";
          for(int i=0; i<A.length(); i++){
              
           ch=A[i];
          
           //counting 
            count[ch]++;
           // pushing every character after counting
            q.push(ch);
            
            while(!q.empty()){

                // here Assuming that queue should have only Non-repeating character. so if found repeating then pop it
                if(count[q.front()]>1){
                    q.pop();
                }
                else{
                    // if found non-repeating then store or push  queue's front becoz front will always contain first non repeating character and current non repeating character is somewhere after it
                    ans+=q.front();
                    break;
                }
            }
            // if it is out of loop there can be 2 reasons 1) queues is empty means no non repeating character found and have to return '#' 
            //2) Non-repeating character or unique character found
         
            if(q.empty()){
                ans+='#';
            }
            
          }
    
       return ans;

    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
