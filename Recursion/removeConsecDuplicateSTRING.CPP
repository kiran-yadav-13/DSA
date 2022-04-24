# include <iostream>
using namespace std;
void removeDup(string s, int i){
    if(str[i]==str[i+1]){
        s.erase(i,2);
        if(s.length()!=0){
            i--;
        }
    }
}
int main(){

    return 0;
}