#include<iostream>
#include<algorithm>
using namespace std;


int minPrice(int n,int candy[],int k){
    int buy=0;   // buying from the start to pay min amount
    int free=n-1;  // getting free from the end for the max priced candies

    int minCost=0;
    while(buy<=free){
        minCost=minCost+candy[buy];
        buy++;
        free=free-k;
    }
    return minCost;
}


int maxPrice(int n,int candy[],int k){
    int buy=n-1;
    int free=0;

    int maxCost=0;
    while(free<=buy){
        maxCost=maxCost+candy[buy];
        buy--;
        free=free+k;
    }
    return maxCost;
}


int main(){
    int n=4;     // 'n' types if candies
    int candy[]={3,2,1,4}; // price of 'n' types of candies
    int k=2;  // 'k' free candies

    sort(candy,candy+n);   // sorting the prices of the candies

    cout<<"Minimum money to buy all candie is: "<<minPrice(n,candy,k)<<endl;
    cout<<"Maximun money to buy all candie is: "<<maxPrice(n,candy,k)<<endl;



    return 0;
}