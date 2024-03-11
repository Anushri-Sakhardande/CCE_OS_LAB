#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 3

typedef struct{
    int pid;
    int arr_time;
    int bur_time;
    int rem_time;
    int priority;
    bool complete;
}proc;

int waiting[MAX];
int i,j;

void pre_sjf(proc process[], int waiting[]){
    int time=0;
    int tot_comp=0;
    printf("Process\tTime\tCompleted\n");
    while(tot_comp<MAX){
        int min_burst=INT_MAX;
        int min=-1;
        for (int j = MAX - 1; j >= 0; j--) {
            if (process[j].arr_time <= time && !process[j].complete) {
                if (process[j].rem_time < min_burst) {
                    min = j;
                    min_burst = process[j].rem_time;
                }
            }
        }
        if(min>-1){
                process[min].rem_time--;
                time++;
                if(process[min].rem_time==0){
                    waiting[min]=time-process[min].arr_time-process[min].bur_time;
                    process[min].complete=true;
                    tot_comp++;
                }
                printf("%d\t%d\t%d\n",process[min].pid,time,process[min].complete);
            }
            else{
                time++;
                printf("%s\t%d\t%d\n","No process",time,0);
            }
    }
    int avg_wait=0;
    for(i=0;i<MAX;i++){
        avg_wait+=waiting[i];
    }
    avg_wait/=MAX;
    printf("Average waiting time:%d\n",avg_wait);
}

void priority(proc process[], int waiting[]){
    int time=0;
    int tot_comp=0;
    printf("Process\tTime\tCompleted\n");
    while(tot_comp<MAX){
        int min_pri=INT_MAX;
        int min=-1;
        for (int j = MAX - 1; j >= 0; j--) {
            if (process[j].arr_time <= time && !process[j].complete) {
                if (process[j].priority < min_pri) {
                    min = j;
                    min_pri = process[j].priority;
                }
            }
        }
        if(min>-1){
                time+=process[min].bur_time;
                waiting[min]=time-process[min].arr_time-process[min].bur_time;
                process[min].complete=true;
                tot_comp++;
                printf("%d\t%d\t%d\n",process[min].pid,time,process[min].complete);
            }
            else{
                time++;
                printf("%s\t%d\t%d\n","No process",time,0);
            }
    }
    int avg_wait=0;
    for(i=0;i<MAX;i++){
        avg_wait+=waiting[i];
    }
    avg_wait/=MAX;
    printf("Average waiting time:%d\n",avg_wait);
}

int main(){
    proc process[MAX] = {
        {1, 0, 3, 3, 3, false},
        {2, 2, 6, 6, 2, false},
        {3, 4, 4, 4, 1, false}
    };
    int waiting[MAX] = {0};
    pid_t p = fork();
    if (p==0){
        pre_sjf(process,waiting);
    }else{
        priority(process,waiting);
    }
}