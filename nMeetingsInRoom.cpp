#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


static bool comp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}


int maxMeetings(int startTime[],int endTime[],int n){
    vector<pair<int,int>> v;    // vector of pairs to store start time corresponding to the end time

    for(int i=0;i<n;i++){      // making all the pairs of start-end time and storing them in the vector
        pair<int,int> p=make_pair(startTime[i],endTime[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),comp);     //  custom sort with comparater function

    int count=1;      // first meeting will execute everytime
    int ansEnd=v[0].second;  // this is the endTime of the previous meeting....later we'll compare it with the startTime of current meeting

    for(int i=1;i<n;i++){
        if(v[i].first>ansEnd){      // start time of 2nd meeting should be greater than the endTime of previous meeting
            count++;
            ansEnd=v[i].second;    // if meeting happens...update the endTime
        }
    }
    return count;
}


int main(){
    int startTime[]={10,12,20};  // start time of meetings
    int endTime[]={20,25,30};  // end times of meetings
    int n=3;       // number of meetings

    int ans=maxMeetings(startTime,endTime,n);
    cout<<"Max meetings are: "<<ans<<endl;

    return 0;
}