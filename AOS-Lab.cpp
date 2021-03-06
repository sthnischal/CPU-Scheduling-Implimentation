#include<iostream>
#include<conio.h>
#include<stdio.h>
 class cpuschedule
{
	int n,Bu[20];
	float Twt,Awt,A[10],Wt[10],w,tat,atat,at;
 public:
	//Getting the No of processes & burst time
	void Getdata();
	//First come First served Algorithm
	void Fcfs();
	//Shortest job First Algorithm
	void Sjf();
	//Shortest job First Algorithm with Preemption
	void SjfP();
	//Shortest job First Algorithm with NonPreemption
	void SjfNp();
	//Round Robin Algorithm
	void RoundRobin();
	//Priority Algorithm
	void Priority();
};
// Implementation file for Cpu scheduling
//#include "cpuh.h"
//Getting no of processes and Burst time
void cpuschedule::Getdata()
{
	using namespace std;
	int i;
	cout<<"Enter the no of processes: ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter The BurstTime for Process p"<<i<<"= ";
		cin>>Bu[i];
	}
}
//First come First served Algorithm
void cpuschedule::Fcfs()
{
	using namespace std;
	int i,B[10];
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		at+= B[i];
		cout<<"\nBurst time for process p"<<i<<"= "<<B[i];
		//cout<<B[i];
	}
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}
	//Calculating Average Waiting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	//Calculating turnaround time
					//		tat=Twt+B[i];
					//        atat = tat / n;
					//		
					//		Awt=Twt/n;
			tat=Twt+at;
            atat = tat / n;
            Awt = Twt / n;
	cout<<"\nTotal Waiting Time= "<<Twt;
	cout<<"\nAverage Waiting Time= "<<Awt<<"";
	cout<<"\nTotal Turn Around Time= " <<tat;
	cout<<"\nAverage Turn Around Time= "<<atat<<"\n\n\n";
}
//Shortest job First Algorithm
void cpuschedule::Sjf()
{
	using namespace std;
	int i,j,temp,B[10];
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		at+= B[i];
		cout<<"\nBurst time for process p"<<i<<"=	";
		cout<<B[i];
	}
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(B[j-1]>B[j])
			{
				temp=B[j-1];
				B[j-1]=B[j];
				B[j]=temp;
			}
		}
	}
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}
	//calculating Average Waiting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
		Awt=Twt/n;
		atat = tat / n;
        Awt = Twt / n;
	cout<<"\nTotal Waiting Time="<<Twt;
	cout<<"\nAverage Waiting Time="<<Awt<<"";
	cout<<"\nTotal Turn Around Time="<<tat;
    cout<<"\nAverage Turn Around Time="<<atat;
}
//Shortest job First Algorithm with NonPreemption
void cpuschedule::SjfNp()
{
	using namespace std;
	int i,B[10],Tt=0,temp,j;
	char S[10];
	float A[10],temp1,t;
	Twt=0.0;
	w=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"\nBurst time for process p"<<i<<"=	";
		cout<<B[i];
		S[i]='T';
		Tt=Tt+B[i];
		cout<<"\nEnter the Arrival Time for"<<i<<"th process=	";
		cin>>A[i];
	}
	for(i=n;i>=1;i--)
	{
		for(j=3;j<=n;j++)
		{
			if(B[j-1]>B[j])
			{
				temp=B[j-1];
				temp1=A[j-1];
				B[j-1]=B[j];
				A[j-1]=A[j];
				B[j]=temp;
				A[j]=temp1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<"p"<<i<<"	"<<B[i]<<"	"<<A[i];
	}
	//For the 1st process
		Wt[1]=0;
		w=w+B[1];
		t=w;
		S[1]='F';
		while(w<Tt)
		{
			i=2;
			while(i<=n)
			{
				if(S[i]=='T'&&A[i]<=t)
				{
					Wt[i]=w;
					cout<<"WT"<<i<<"="<<Wt[i];
					S[i]='F';
					w=w+B[i];
					t=w;
					i=2;
				}
				else
					i++;
			}
		}
		for(i=1;i<=n;i++)
			cout<<"Wt"<<i<<"=="<<Wt[i];
		//calculating average Waiting Time
		for(i=1;i<=n;i++)
			Twt=Twt+(Wt[i]-A[i]);
		Awt=Twt/n;
	cout<<"\nTotal Waiting Time="<<Twt<<"";
	cout<<"\nAverage Waiting Time="<<Awt<<"";
}
//Priority Algorithm
void cpuschedule::Priority()
{
	using namespace std;
	int i,B[10],P[10],j;
	w=0.0;
	int max;
	Twt=0.0;
	max=1;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		at += B[i];
		cout<<"\nBurst time for process p"<<i<<"=	";
		cout<<B[i];
		cout<<"\nEnter the priority for process P"<<i<<"=	";
		cin>>P[i];
		if(max<P[i])
			max=P[i];
	}
	j=1;
	while(j<=max)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				Wt[i]=w;
				w=w+B[i];
			}
			i++;
		}
		j++;
	}
	//calculating average Waiting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
		Awt=Twt/n;
		
		tat = Twt + at;
        atat = tat / n;
	cout<<"\nTotal Waiting Time= "<<Twt<<"";
	cout<<"\nAverage Waiting Time= "<<Awt<<"";
	cout<<"\nTotal Turn Around Time= "<< tat;
    cout<<"\nAverage Turn Around Time= "<< atat;
}
//Shortest job First Algorithm with Preemption
void cpuschedule::SjfP()
{
	using namespace std;
	int i,j,m,Wt[10],k,B[10],A[10],Tt=0,Wtm[10],temp;
	char S[20],start[20];
	int max=0,Time=0,min;
	float Twt=0.0,Awt;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"\nBurst time for process P"<<i<<"=	"<<B[i];
		if(B[i]>max)
			max=B[i];
		Wt[i]=0;
		S[i]='T';
		start[i]='F';
		Tt=Tt+B[i];
		cout<<"\nEnter the Arrival Time for"<<i<<"th process=	";
		cin>>A[i];
		if(A[i]>Time)
			Time=A[i];
	}
	cout<<"Max="<<max;
	int w=0,flag=0,t=0;
	i=1;
	while(t<Time)
	{
		if(A[i]<=t && B[i]!=0)
		{
			if(flag==0)
			{
				Wt[i]=Wt[i]+w;
				cout<<"Wt["<<i<<"]="<<Wt[i];
			}
			B[i]=B[i]-1;
			if(B[i]==0)
				S[i]='F';
			start[i]='T';
			t++;
			w=w+1;
			if(S[i]!='F')
			{
				j=1;flag=1;
				while(j<=n && flag!=0)
				{
					if(S[j]!='F' && B[i]>B[j] && A[j]<=t && i!=j )
					{
						flag=0;
						Wt[i]=Wt[i]-w;
						i=j;
					}
					else
					{
						flag=1;
					}
					j++;
				}
			}
			else
			{
				i++;
				j=1;
				while(A[j]<=t &&j<=n)
				{
					if(B[i]>B[j] && S[j]!='F')
					{
						flag=0;
						i=j;
					}
					j++;
				}
			}
		}
		else
			if(flag==0)
			i++;
	}
	cout<<"\nPrinting remaining burst time";
	for(i=1;i<=n;i++)
		cout<<"B["<<i<<"]="<<B[i];
	cout<<"";
	while(w<Tt)
	{
		min=max+1;
		i=1;
		while(i<=n)
		{
			if(min>B[i] && S[i]=='T')
			{
				min=B[i];
				j=i;
			}
			i++;
		}
		i=j;
		if(w==Time && start[i]=='T')
		{
			w=w+B[i];
			S[i]='F';
		}
		else
		{
			Wt[i]=Wt[i]+w;
			w=w+B[i];
			S[i]='F';
		}
	}
cout<<"Weight info";
	for(i=1;i<=n;i++)
		cout<<"WT["<<i<<"]="<<Wt[i];
cout<<"\nAfter subtracting arrival time";
	for(i=1;i<=n;i++)
	{
		Wt[i]=Wt[i]-A[i];
		cout<<"WT["<<i<<"]="<<Wt[i];
	}
	//Calculating Average Waiting time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
		Awt=Twt/n;
		
		tat = Twt + at;
        atat = tat / n;
	cout<<"\nAverage Waiting Time="<<Awt;
	cout<<"\nTotal Waiting Time ="<<Twt;
	cout<<"\nTotal Turn Around Time="<<tat;
    cout<<"\nAverage Turn Around Time="<<atat;
      
}
//Round Robin Algorithm
void cpuschedule::RoundRobin()
{
	using namespace std;
	int i,j,tq,k,B[10],Rrobin[10][10],count[10];
	int max=0;
	int m;
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		at+= B[i];
		cout<<"\nBurst time for process p"<<i<<"=	";
		cout<<B[i];
		if(max<B[i])
			max=B[i];
		Wt[i]=0;
	}
	cout<<"\nEnter the Time Quantum=";
	cin>>tq;
	//TO find the dimension of the Rrobin array
	m=max/tq+1;
	//initializing Rrobin array
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			Rrobin[i][j]=0;
		}
	}
	//placing value in the Rrobin array
	i=1;
	while(i<=n)
	{
		j=1;
		while(B[i]>0)
		{
			if(B[i]>=tq)
			{
				B[i]=B[i]-tq;
				Rrobin[i][j]=tq;
				j++;
			}
			else
			{
				Rrobin[i][j]=B[i];
				B[i]=0;
				j++;
			}
		}
		count[i]=j-1;
		i++;
	}
	cout<<"Display";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"\nRr["<<i<<","<<j<<"]="<<Rrobin[i][j];
			cout<<"	";
		}
		cout<<"";
	}
	//calculating Waiting time
	int x=1;
	i=1;
	while(x<=n)
	{
		for(int a=1;a<x;a++)
		{
			Wt[x]=Wt[x]+Rrobin[a][i];
		}
		i=1;
		int z=x;
		j=count[z];
		k=1;
		while(k<=j-1)
		{
			if(i==n+1)
			{
				i=1;
				k++;
			}
			else
			{
				if(i!=z)
				{
					Wt[z]=Wt[z]+Rrobin[i][k];
				}
				i++;
			}
		}
		x++;
	}
	for(i=1;i<=n;i++)
		cout<<"\nWaiting Time for process P"<<i<<"="<<Wt[i];
	//calculating Average Waiting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
		
		tat = Twt + at;
	    atat = tat / n;
		Awt=Twt/n;
			    
	cout<<"\nTotal Waiting Time="<<Twt;
	cout<<"\nAverage Waiting Time="<<Awt<<"";
	cout<<"\nTotal Turnaround Time="<<Twt;
	cout<<"\nAverage Turnaround Time="<<Awt<<"\n";
}
//Application file for cpu Scheduling
//#include "cpuh.h"
int main()
{
	using namespace std;
	int ch,cho;
	cpuschedule c;
	do
	{
		cout<<" MENU\n";
		cout<<"1.Getting BurstTime\n";
		cout<<"2.FirstComeFirstServed\n";
		cout<<"3.ShortestJobFirst\n";
		cout<<"4.RoundRobin\n";
		cout<<"5.Priority\n";
		cout<<"6.EXIT\n";
		cout<<"Enter your choice:  ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			c.Getdata();
			break;
		case 2:
			cout<<"FIRST COME FIRST SERVED SCHEDULING";
			c.Fcfs();
			break;
		case 3:
			cout<<"SHORTEST JOB FIRST SCHEDULING\n";
			do
			{
				cout<<"\n1.SJF-Normel";
				cout<<"\n2.SJF-Preemptive";
				cout<<"\n3.SJF-NonPreemptive";
				cout<<"\nEnter your choice:  ";
				cin>>cho;
				switch(cho)
				{
				case 1:
					c.Sjf();
					break;
				case 2:
					c.SjfP();
					break;
				case 3:
					c.SjfNp();
					break;
				}
			}while(cho<=3);
			break;
		case 4:
			cout<<"ROUND ROBIN SCHEDULING";
			c.RoundRobin();
			break;
		case 5:
			cout<<"PRIORITY SCHEDULING";
			c.Priority();
			break;
		case 6:
			break;
		}
	}while(ch<=5);
}
