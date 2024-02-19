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

void input_proc(proc *process){
    int i;
    for(i=0;i<5;i++){
		printf("Enter the process id, arrival time and burst time");
		scanf("%d",&process[i].pid);
		scanf("%d",&process[i].arrival_time);
		scanf("%d",&process[i].burst_time);
		process[i].completed=false;
	}
}

void pre_sjf(proc *process,){

}

void rr(){

}

void nonpre_pr(){

}


int main(){
    int choice;
    int waiting_time[6];
    int turnaround_time[6];
    proc process[5];
    while(true){
        printf("Would you like to perform");
        printf("0.Exit");
        printf("1.Preemptive Shortest Job First(SJF)");
        printf("2.Round Robin(RR)");
        printf("3.Non-preemptive priority Scheduling");
        scanf("%d",&choice);
        if(choice!=0){
            input_proc(process)
        }
        switch(choice){
            case 1:
                pre_sjf();
                break;
            case 2:
                rr();
                break;
            case 3:
                nonpre_pri();
                break;
            case 0:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Invalid option");
        }
    }
}