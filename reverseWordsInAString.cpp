#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s="I love you";
    string ans="";   // storing the final answer
    string temp="";  // storing each word for reversing

    for(int i=s.length()-1;i>=0;i--){     // traversing the string from end to start

        if(s[i]==' '){    // if space comes, reverse the word and append it in the answer
            reverse(temp.begin(),temp.end());
            ans=ans+temp+' ';
            temp="";
        }
    
        else{    // if not space, push letter in the temp string
            temp.push_back(s[i]);
        }
    }

    reverse(temp.begin(),temp.end());  // reversing the first word
    ans=ans+temp;  // appending first word in the answer string
    cout<<"Reversed string is: "<<ans<<endl;

    return 0;
}