# include <iostream>
# include <vector>
using namespace std;
int CompressedStrings(vector<char>& chars){
    int start=0;
    int end=start;
    vector<char> NewChar;
    int count=0;
    while(end<=(chars.size()-1)){
      if(chars.at(start)==chars.at(end)){
        count++;
        end++;
      }
      else{
          NewChar.push_back(chars.at(start));
          if(count!=1){
              NewChar.push_back(to_string(count));
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
   cout<<"Size of Compressed character array is : "<<CompressedStrings(name);

    return 0;
}
