#include<iostream>
using namespace std;
int main()
{
 cout<<"How much processes you need to demonstrate: Please enter the number: "<<endl;
 int Total_Processes=0;
 cin>>Total_Processes;
 
 cout<<"Please enter the burst times for each processes: "<<endl;
 int BurstTime[10][5];
 for(int i =0;i<Total_Processes;++i)
 {
  cin>>BurstTime[i][0];
  BurstTime[i][1]=BurstTime[i][0]; 
  
  BurstTime[i][2]=0; 
  
  BurstTime[i][3]=0; 
  
  BurstTime[i][4]=0; 
  
 }
 int time=0;
 cout<<"Please enter the time quantum: ";
 cin>>time;
 while(1)
 {
  bool resume = 0;
  for(int i =0;i<Total_Processes;++i)
  {
   if(BurstTime[i][4]==0)
   {
    resume = 1;
    break;
   }
  }
 
  if(resume)
  {
   for(int i =0;i<Total_Processes;++i)
   {
    if(BurstTime[i][1]<=time)
    {
     for(int j=0;j<Total_Processes;++j)
     {
      if(i==j)
       continue;
      else if(BurstTime[j][4]==0)
      BurstTime[j][2]+=BurstTime[i][1];
     }
     BurstTime[i][1]=0;
     BurstTime[i][4]=1;
    }
    else if(BurstTime[i][1]>time)
    {
     BurstTime[i][1]-=time;
     for(int j =0;j<Total_Processes;++j)
     {
      if(i==j)
       continue;
      else if(BurstTime[j][4]==0)
      BurstTime[j][2]+=time;
     }
    }
   }
  }
  else if(!resume)
   break;
 }
 float AverageWaitingTime =0, AverageTurnAroungTime =0;
 
  for(int i=0;i<Total_Processes;++i)
  {
     BurstTime[i][3] = BurstTime[i][0]+BurstTime[i][2];
  AverageWaitingTime+=BurstTime[i][2];
  AverageTurnAroungTime+=BurstTime[i][3];
  }
  AverageWaitingTime/=Total_Processes;
  AverageTurnAroungTime/=Total_Processes;
 
   
   for(int i = 0;i<Total_Processes;++i)
   {
     cout<<"Total_Processesess ID is =  "<<i<<endl;
     cout<<"Burst time is = "<<BurstTime[i][0]<<endl;
     cout<<"Waiting time is= "<<BurstTime[i][2]<<endl;
     cout<<"Turn Around Time  is= "<<BurstTime[i][3]<<endl;
     cout<<endl<<endl;
   }
   cout<<"Average turn around time is = "<<AverageTurnAroungTime<<endl;
   cout<<"Average waiting time is = "<<AverageWaitingTime<<endl;
}
