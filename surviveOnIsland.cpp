#include<iostream>
using namespace std;

int survive(int n,int m,int s){

    int sundays=s/7;     // counting sundays
    int buyingDays=s-sundays;     // reducing sundays from total no of days
    int ans=0;

    int totalFood=m*s;   // total food required to survive

    if(totalFood%n==0){    // exact food for 's' days
        ans=totalFood/n;
    }
    else{
        ans=totalFood/n + 1;   // need some more food
    }

    if(ans<=buyingDays){
        return ans;         // for survival
    }
    else{
        return -1;    // you are dead
    }
}



int main(){
    int n=16;   // food can buy per day
    int m=2;   // food needed per day to survive
    int s=10;   // days to survive

    int ans=survive(n,m,s);

    if(ans!=-1){
        cout<<"Min days to buy food: "<<ans<<endl;
    }
    else{
        cout<<"YOu are dead"<<endl;
    }

    return 0;
}