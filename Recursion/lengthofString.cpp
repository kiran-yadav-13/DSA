# include <iostream>
# include <string>
using namespace std;
int length(string str, int i){
    if(str[i]=='\0'){
        return i;
    }
    return length(str, i+1);

}
int main(){
    string str;
    cin>>str;
    cout<<length(str, 0);

    return 0;
}