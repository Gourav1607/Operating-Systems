/*
 *  pcb.h / FCFS
 *  Created on: 16-Nov-2014
 *      Author: Gourav Siddhad
 */

#ifndef PCB_H_
#define PCB_H_

using namespace std;

class PCB
{
	int pid;
	float at,bt,tt,rt,wt;
	bool done;
	public:
		PCB();
		void input();
		void put_pid(int);
		void change_done();
		void put_tt(float);
		void put_rt(float);
		void put_wt(float);
		int return_pid();
		float return_at();
		float return_bt();
		float return_tt();
		float return_wt();
		float return_rt();
};

PCB :: PCB()
{
	at=bt=tt=rt=wt=0;
	pid=0;
	done=false;
}

void PCB :: change_done()
{
	done = !done;
}

void PCB :: input()
{
	cout<<"\n Enter Arrival Time : ";
	cin>>at;
	cout<<" Enter Burst Time : ";
	cin>>bt;
}

void PCB :: put_pid(int n)
{
	pid=n;
}

void PCB :: put_tt(float t)
{
	tt=t;
}
void PCB :: put_rt(float r)
{
	rt=r;
}
void PCB :: put_wt(float w)
{
	wt=w;
}

int PCB :: return_pid()
{
	return pid;
}

float PCB :: return_at()
{
	return at;
}

float PCB :: return_bt()
{
	return bt;
}

float PCB :: return_tt()
{
	return tt;
}

float PCB :: return_rt()
{
	return rt;
}

float PCB :: return_wt()
{
	return wt;
}

#endif /* PCB_H_ */
