#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int swim,cycle,run,time;
}Man;

void change(Man *a,Man *b){
    Man t=*a;
    *a=*b;
    *b=t;
}

void sort(Man arr[],int n){
    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].time>arr[k].time){
                k=j;
            }
        }
        change(&arr[i],&arr[k]);
    }
}

int calculate(Man arr[],int n){
    int swimtime[n];
    int finishtime[n];

    swimtime[0]=arr[0].swim;
    for(int i=1;i<n;i++){
        swimtime[i]=swimtime[i-1]+arr[i].swim;
    }

    int k=0;
    while(k<n){
        finishtime[k]=swimtime[k]+arr[k].cycle+arr[k].run;
        k++;
    }

    int maxtime=finishtime[0];
    for(int i=1;i<n;i++){
        if(finishtime[i]>maxtime){
            maxtime=finishtime[i];
        }
    }
    return maxtime;
}

int main(){
    int n;
    scanf("%d",&n);
    Man arr[n];
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&arr[i].swim,&arr[i].cycle,&arr[i].run);
        arr[i].time=arr[i].cycle+arr[i].run;
    }

    sort(arr,n);
    printf("%d\n",calculate(arr,n));
    return 0;
}
