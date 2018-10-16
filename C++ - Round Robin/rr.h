/*
 *  rr.h / Round Robin
 *  Created on: 16-Nov-2014
 *      Author: Gourav Siddhad
 */

#ifndef RR_H_
#define RR_H_

#include "iostream"
#include "iomanip"
#include "pcb.h"
using namespace std;

void sort(PCB[],int);
void rr(PCB[],int,int);
void printtable(PCB[],int);

void sort(PCB p[],int n)
{
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
			if(p[min].return_at() > p[j].return_at())
				min=j;

		PCB temp;
		temp=p[min];
		p[min]=p[i];
		p[i]=temp;

		p[i].put_pid(i);
	}
}

void rr(PCB p[],const int n,int t)
{
	PCB d[n];
	bool alldone=false;
	float clk=0;

	for(int i=0;i<n;i++)
		d[i]=p[i];

	clk = p[0].return_at();
	while(!alldone)
	{
		for(int i=0;i<n;i++)
		{
			if(!p[i].return_done())
			{
				if(p[i].return_bt() == d[i].return_bt())
					p[i].put_rt(clk-p[i].return_at());
				if(p[i].return_bt() <= t)
				{
					clk += p[i].return_bt();
					p[i].put_done(true);
					p[i].put_bt(0);
					p[i].put_tt(clk-p[i].return_at());
					p[i].put_wt(p[i].return_tt()-p[i].return_bt());
				}
				else
				{
					alldone=false;
					clk += t;
					p[i].put_bt(p[i].return_bt() - t);
				}
			}
		}
		alldone=true;
		for(int i=0;i<n;i++)
			if(p[i].return_bt() != 0)
			{
				alldone=false;
				break;	
			}
	}
}

void printtable(PCB p[],int n)
{
	cout<<"\n |  PID |  AT  |  BT  |  TT  |  RT  |  WT  |";
	for(int i=0;i<n;i++)
	{
		cout<<endl<<" | ";
		cout<<setw(4)<<p[i].return_pid()<<" | "<<setw(4)<<p[i].return_at()<<" | ";
		cout<<setw(4)<<p[i].return_bt()<<" | "<<setw(4)<<p[i].return_tt()<<" | ";
		cout<<setw(4)<<p[i].return_rt()<<" | "<<setw(4)<<p[i].return_wt()<<" | ";
	}
	float av_tt,av_rt,av_wt;
	av_tt=av_rt=av_wt=0;
	for(int i=0;i<n;i++)
	{
		av_tt+=p[i].return_tt();
		av_rt+=p[i].return_rt();
		av_wt+=p[i].return_wt();
	}
	av_tt/=n;	av_rt/=n;	av_wt/=n;
	cout<<"\n Average TT : "<<av_tt;
	cout<<"\n Average RT : "<<av_rt;
	cout<<"\n Average WT : "<<av_wt;
}

#endif /* RR_H_ */
