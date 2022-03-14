# include <iostream>
# include <vector>
using namespace std;
int CompressedString(vector<char>& chars){
  int i=0;
  int ansIndex=0;
  int n=chars.size();
  while(i<n){
    int j=i+1;
    while(j<n && chars[i]==chars[j]){
      j++;
    }
    //yaha kab aaoge - jab pura vector traverse kar liya ho
    // ya phir different character encounter kiya ho
    //old character store kar lo
    chars[ansIndex++]=chars[i];
    int count =j-i;
    if(count>1){
      string cnt=to_string(count);
      for(char ch : chars){
         chars[ansIndex++]=ch;
      }
    }
    i=j;
  }
  for(int i=0; i<chars.size(); i++){
       cout<<chars[i]<<" ";
   }
  return ansIndex;
}
int CompressedStrings(vector<char>& chars){
    int start=0;
    int end=start;
    vector<char> NewChar;
    int count=0;
    cout<<" End outside loop "<<end<<endl;
    while(end<=(chars.size()-1)){

      if(chars.at(start)==chars.at(end)){
         cout<<" End inside  loop  if part "<<chars[start]<<'\t'<<chars[end]<<'\t'<<end<<endl;
        count++;
       end++;
      
      }
     else if((chars.at(start)!=chars.at(end)) | end==(chars.size()-1)){
          NewChar.push_back(chars.at(start));
         cout<<" End inside  loop  else part"<<chars[start]<<'\t'<<chars[end]<<" "<<end<<endl;
          if(count>1){
            // converting counting into single digit 
            string cnt=to_string(count);
            for(int i=0; i<cnt.length(); i++){
              NewChar.push_back(cnt[i]);
            }
          }
          start=end;
          count=0;
           
      }
      
    }
    
    for(int i=0; i<NewChar.size(); i++){
       cout<<NewChar.at(i)<<" ";
   }
   cout<<endl;
    return NewChar.size();
}
int main(){
  vector<char> name;
   int n;
   char c;
   cout<<"How many characters do you want in character array : ";
   cin>>n;
   cout<<"Enter a character array : ";
   for(int i=0; i<n; i++){
       cin>>c;
       name.push_back(c);
   }
   cout<<"Size of Compressed character array is : "<<CompressedString(name);

    return 0;
}