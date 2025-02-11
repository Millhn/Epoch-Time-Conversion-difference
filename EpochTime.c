#include <stdio.h> //for input/output functions
#include <stdlib.h> //for general utilities
#include <time.h> //for time-related functions


//to hold date and time information
struct DateTime{
	int year, month, day, hour, minute, second;
};
//to store both date and epoch time
union {
	struct DateTime date;
	time_t epoch;
}DateEpoch;

//to convert DateTime struct to epoch time
time_t convert_to_epoch(struct DateTime date){
	struct tm t;
	t.tm_year =date.year-1900; // tm struct counts years from 1900
	t.tm_mon =date.month-1; // tm struct uses 0-11 for months
	t.tm_mday =date.day;
	t.tm_hour =date.hour;
	t.tm_min =date.minute;
	t.tm_sec =date.second;
	t.tm_isdst = -1; //let system determine daylight saving time
	
	return mktime(&t); // convert to epoch time
}
//to display difference in days, hours, minutes, and seconds 
void display_difference(double diff_seconds) {
    //convert total seconds into days
	int days = diff_seconds / (24 * 3600);
    diff_seconds -= days * 24 * 3600;
    // convert remaining seconds into hours
	int hours = diff_seconds / 3600;
    diff_seconds -= hours * 3600;
    //convert remaining seconds into minutes
	int minutes = diff_seconds / 60;
    //remaining seconds
	int seconds = (int)diff_seconds % 60;

    printf("Difference: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
}

//to get date and time input from the user
int main() {
	struct DateTime date1, date2;
	time_t epoch1, epoch2;
	double difference;
		
	printf("\tInput the first date:\n");
	printf("Year (1970-now):");
	scanf("%d", &date1.year);
	printf("Month (01-12):");
	scanf("%d", &date1.month);
	printf("Day (01-31):");
	scanf("%d", &date1.day);
	printf("Hour (00-23):");
	scanf("%d", &date1.hour);
	printf("Minute (00-59):");
	scanf("%d", &date1.minute);
	printf("Second (00-59):");
	scanf("%d", &date1.second);

	printf("\tInput the second date:\n");
	printf("Year (1970-now):");
	scanf("%d", &date2.year);
	printf("Month (01-12):");
	scanf("%d", &date2.month);
	printf("Day (01-31):");
	scanf("%d", &date2.day);
	printf("Hour (00-23):");
	scanf("%d", &date2.hour);
	printf("Minute (00-59):");
	scanf("%d", &date2.minute);
	printf("Second (00-59):");
	scanf("%d", &date2.second);
	printf("\n");
//processing and output		
	epoch1 = convert_to_epoch(date1);
	epoch2 = convert_to_epoch(date2);
	
	//to check for conversion error
	if (epoch1 == -1 || epoch2 == -1){
		printf("Conversion error : invalid date or time\n");
		return 1;
	}
	//to display dates in both formats
	printf("First date (local time): %04d-%02d-%02d  %02d:%02d:%02d\n", date1.year,date1.month,date1.day,date1.hour,date1.minute,date1.second);
	printf("Second date (local time): %04d-%02d-%02d  %02d:%02d:%02d\n\n", date2.year,date2.month,date2.day,date2.hour,date2.minute,date2.second);
	printf("First date (epoch time): %ld\n", epoch1);
	printf("Second date (epoch time): %ld\n\n", epoch2);
	//calculate and display difference 
	difference = difftime(epoch2, epoch1);
	printf("Difference between 2 date above: %.0f second\n", difference);
	display_difference (difference);
	return 0;
}
