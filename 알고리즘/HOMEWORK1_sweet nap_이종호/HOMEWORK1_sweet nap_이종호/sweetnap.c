//This program calculates empty schedules. User inputs theirs schedule time.
//So, It converts character type to integer type and then calculates empty time.

#include <stdio.h>
#include <stdlib.h>
#define DAY 3
int getHour(char *time){ //Convert character to integer. So this function returns hours integer value.
	int hour;
	char temp[2];
	temp[0] = time[0];
	temp[1] = time[1];
	hour = atoi(temp);
	return hour;

}
int getMinute(char *time){//Convert character to integer. So this function returns minutes integer value.
	int minute;
	char temp[2];
	temp[0] = time[3];
	temp[1] = time[4];
	minute = atoi(temp);
	return minute;
}
int computeMinute(int *time1, int *time2){//Calculates minutes those start time minus end time. so return minutes integer value.
	int result;
	int hour;
	int minute;
	hour =time1[0] - time2[0];
	minute = time1[1] - time2[1];

	if(minute < 0){
		hour--;
		minute = 60 + minute;
	}
	result = hour*60 + minute;
	return result;
}
void computeHour(int *hour,  int *minute, int longest){ //Calculates minutes to hour. It has two pointer, So, it saves values directly.
	*hour = longest/60;
	*minute = longest - *hour*60;
}

void main(){
	int i,j;
	int temp = 0, temp2 = 0;
	int napStart[2];
	int longest;
	int time1[2], time2[2];

	char start[6]="";
	char end[6]="";
	char schedule[50]="";

	int resultHour , resultMinute;

	int task = 0;



	for(i = 0; i < DAY; i++){
		printf("Enter the number of task : \n");
		scanf("%d",&task);
		while(task > 100){
			printf("You must enter the number smaller than 100\n");
			scanf("%d",&task);
		}
		temp = 0;
		temp2 = 0;
		longest = 0;
		for( j = 0; j < task; j++){
			scanf("%s %s %s",start, end, schedule);
			time1[0] = getHour(start);
			time1[1] = getMinute(start);

			if(j != 0){
				if(time2[0] != time1[0] || time2[1] != time1[1]){
					temp2 = computeMinute(time1,time2);
					if(temp2 > longest){
						longest = temp2;
						napStart[0] = time2[0];
						napStart[1] = time2[1];
					}
				}
			}
			time2[0] = getHour(end);
			time2[1] = getMinute(end);
		}
		computeHour(&resultHour,&resultMinute, longest);
		if(longest == 0)
			printf("\nDay #%d : there are no time to nap.\n",i+1);
		else{
		printf("\nDay #%d : the longest nap starts at %d : ",i+1, napStart[0]);
		if(napStart[1]<10)
			printf("0%d",napStart[1]);
		else
			printf("%d",napStart[1]);
		if(resultHour<=0)
			printf(" and will last for %d minutes.\n",resultMinute);
		else if(resultMinute <= 0)
			printf(" and will last for %d hours.\n",resultHour);
		else
			printf(" and will last for %d hours %d minutes. \n",resultHour,resultMinute);
		}
	}
}
