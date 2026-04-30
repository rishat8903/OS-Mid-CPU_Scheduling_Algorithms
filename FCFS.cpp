/// First Come First Service algorithm code with idle time and gantt chart 

#include<bits/stdc++.h>
using namespace std;

struct process {
    string pid;
    int at, bt;
    int ct, tat, wt;
};

int main(){

    int n, i, j;
    cin>>n;
    process p[n];
    for(i=0; i<n; i++){
        cin>>p[i].pid>>p[i].at>>p[i].bt;
    }
    for(i=0; i<n-1; i++){
        for (j=i+1; j<n; j++){
            if(p[i].at>p[j].at ||(p[i].at==p[j].at && p[i].pid>p[j].pid)) {
                swap(p[i], p[j]);
            }
        }
    }
    int time=0;
    string ganttPID[100];
    int ganttTime[100];
    int g=0, idx=0;
    ganttTime[g++]=0;
    for(i=0; i<n; i++){
        while(time<p[i].at){
            ganttPID[idx++]="IDLE";
            time++;
            ganttTime[g++]=time;
        }
        ganttPID[idx++]=p[i].pid;
        time+=p[i].bt;
        ganttTime[g++]=time;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    cout<<"\nGantt Chart:\n";
    cout<<"| ";
    for(i=0; i<idx; i++) {
        cout<<ganttPID[i]<<" | ";
    }
    cout<<"\n";
    for(i=0; i<g; i++){
        cout<<ganttTime[i]<<"    ";
    }
    float total_wt=0, total_tat=0;
    cout << "\n\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0; i<n; i++){
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"
             <<p[i].tat<<"\t"
             <<p[i].wt<<endl;
        total_wt+=p[i].wt;
        total_tat+=p[i].tat;
    }
    cout<<"\nAverage Waiting Time: "<<total_wt/n<<endl;
    cout<<"Average Turnaround Time: "<<total_tat/n<<endl;
    return 0;
}

/*
5
P1 3 4
P2 5 3
P3 0 2
P4 5 1
P5 4 3
*/
