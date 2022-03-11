// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.
// Example 1
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba")
# include <iostream>
# include <string>
using namespace std;
bool countEqual(int a[26], int b[26]){
    for(int i=0; i<26; i++){
        if(a[i]!=b[i])
        {
            return 0;
        }

    }
    return 1;
}
bool checkPermutation(string str1, string str2){
    int count[26]={0};
    // counting the occurences of characters in the string str1 ( for which the permutation we have to find)
    for(int i=0; i<=str1.length(); i++){
        int index=str1[i]-'a';
        count[index]++;
    }
    // traverse str2 (the complete string) string in the window of the  str1 length and compare

    int i=0;
    int windowSize=str1.length();
    int count2[26]={0};
    //traversing 1st window
    while(i<=windowSize){
        int index=str2[i]-'a';       // here the index is position at which the particular character lie in the arrray of letters
     count2[index]++;
     i++;
    }
    //compares if the no of element in the count2 array (array containing count of no of element in particular window)
    // if equal this means that element in the window is the permutation of the given string
    if(countEqual(count, count2)){
        return 1;
    }
   // now creating other windows (till str2.length()) and compairing
   while(i<str2.length())
   {
       char newChar=str2[i];
        int index = newChar-'a';
        count2[index]++;
        char oldChar=str2[i-windowSize];
        index=oldChar-'a';
        count2[index]--;
         if(countEqual(count, count2)){
        return 1;
    } 
    i++;
   }
   return 0;
}
int main(){
   string name,sub;
   int n;
   cout<<"Enter a String : ";
   getline(cin,name);
   cout<<"Enter the substring : ";
   cin>>sub;
     cout<<" Permutation of substring exsist or not : "<<checkPermutation(name,sub);
return 0;
}