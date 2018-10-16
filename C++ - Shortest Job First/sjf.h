/*
 *  sjf.h / SJF
 *  Created on: 16-Nov-2014
 *      Author: Gourav Siddhad
 */

#ifndef SJF_H_
#define SJF_H_

#include "iostream"
#include "iomanip"
#include "pcb.h"
using namespace std;

void sort(PCB[],int);
void sjf(PCB[],int);
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

void sjf(PCB p[],int n)
{
	float clk=p[0].return_at();
	for(int i=0;i<n;i++)
	{
		int min=0;
		for(int j=1; j<n ;j++)
			if(!p[j].return_done())
				min=j;
		for(int j=0; j<n ;j++)
			if((p[min].return_bt() > p[j].return_bt()) && p[j].return_at() <= clk)
				min=j;

		p[min].put_tt(clk + p[min].return_bt() - p[min].return_at());
		p[min].put_rt(clk - p[min].return_at());
		p[min].put_wt(clk - p[min].return_at());

		clk += p[min].return_bt();
		p[min].put_done(true);
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

#endif /* FCFS_H_ */
