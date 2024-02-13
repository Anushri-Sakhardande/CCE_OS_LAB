#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct{
	int arrival_time;
	int burst_time;
	int pid;
	bool completed;
}proc;

int main(){
	int time=0;
	int waiting_time[4];
	int turaround_time[4];
	proc process[3];
	int i,j;
	int tot_comp=0;
	for(i=0;i<3;i++){
		printf("Enter the process burst time and id");
		scanf("%d",&process[i].burst_time);
		scanf("%d",&process[i].pid);
		scanf("%d",&process[i].arrival_time);
		process[i].completed=false;
	}
	while(tot_comp<3){
		int min_burst=INT_MAX;
		int min=-1;
		for(j=0;j<3;j++){
			if(process[j].arrival_time<=time && !process[j].completed && process[j].burst_time < min_burst){
				min=j;
				min_burst = process[j].burst_time;	
			}
			else if(j==2 && min==0){
				time++;
			} 
		}
		if(min>-1){
			time+=process[min].burst_time;
			waiting_time
		}
	}	
	return 0;
}
