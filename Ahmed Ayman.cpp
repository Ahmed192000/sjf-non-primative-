#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    char pname[50];
    int btime;
    int atime;
}a[50];
bool btimeSort(node a,node b){
    return a.btime < b.btime; 
}
bool atimeSort(node a,node b){
    return a.atime < b.atime; 
}
int main(){
    int n;
    cout<<"Enter number of processes\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"please enter the id" <<endl;
        cin>>a[i].pname;
        cout<<"please enter the arrival time" <<endl;
        cin>>a[i].atime;
        cout<<"please enter the brust time" <<endl;
        cin>>a[i].btime;
    }  
    sort(a,a+n,btimeSort);
    sort(a,a+n,atimeSort);
    int ttime=0;
    int i;
    int j,tArray[n];
    for(i=0;i<n;i++){
        j=i;
        while(a[j].atime<=ttime&&j!=n){
            j++;
        }
        sort(a+i,a+j,btimeSort);
        tArray[i]=ttime;
        ttime+=a[i].btime;
    }
    tArray[i] = ttime;
    float averageWaitingTime=0;
    float averageTAT=0;
    cout<<"\n";
    cout<<"P.Name  ArrivalTime\tBrustTime\n";
    for (i=0; i<n; i++){
        cout << a[i].pname << "    \t"; 
        cout << a[i].atime << "        \t";
        cout << a[i].btime << "   \t";
        tArray[i+1];
        tArray[i]-a[i].atime+a[i].btime;
        averageTAT+=tArray[i]-a[i].atime+a[i].btime;
        tArray[i]-a[i].atime ; 
        averageWaitingTime+=tArray[i]-a[i].atime;
        tArray[i]-a[i].atime ;  
        cout <<"\n"; 
    }
    cout<<"\n";
    cout<<"Average Waiting time: "<<(float)averageWaitingTime/(float)n<<endl;
    cout<<"Average TurnAround time: "<<(float)averageTAT/(float)n<<endl; 
    return 0;
}