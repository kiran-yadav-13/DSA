# include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for(int i=0; name[i]!='\0'; i++){
     count++;
   }
   return count;
}
 void swap(char &temp1, char &temp2){
     char temp=temp1;
     temp1=temp2;
     temp2=temp;
 }
void reverse(char str[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){

        swap(str[s], str[e]);
      
            s++;
            e--;
    }
}

int main(){

   char name[20];
   int n;
   cout<<"Enter a character array : ";
   cin>>name;
//    name[3]='\0';
   cout<<"Length of your character array is : ";
   n=getLength(name);
   cout<<n<<endl;
    reverse(name, n);
    cout<<"Reversed string is : "<<name;
   return 0;
}