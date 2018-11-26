#include <stdio.h> //printf, scanf
#include <stdlib.h> //EXIT_FAILURE, EXIT_SUCCESS
/*For a given date, determine which weekday (Monday through Sunday) the date corresponds to, and how many times the given day-and-month
falls on the same weekday starting with the next year and ending on a given year.
*/
int main()
{
	int year, month, day, endyear, counter, year2;
	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &year, &month, &day);
	//cheking validity
	if (year <= 0 || day <= 0 || month <= 0 || month > 12){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	} else if (month == 2 && day > 28){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	} else if (month < 8 && month%2 == 1 && day > 31){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	} else if (month < 8 && month%2 == 0 && day > 30){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	} else if (month >= 8 && month%2 == 0 && day > 31){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	} else if (month >= 8 && month%2 == 1 && day > 30){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	printf("Enter end year: ");
	scanf("%d", &endyear);

	if (endyear <= year){
		printf("End year is less than or equal to the beginning year!\n");
		return EXIT_FAILURE;
	}
	//checking if month is january of february
	if (month == 1 || month == 2){
		month += 12;
		year2 = year-1;
	} else {
		year2 = year;
	}

	int zero_based_cent = year2/100;
	int offset_of_year = year2%100;

	//calculating zellers congruence
	int zeller_day = (day + ((13 * (month + 1))/5) + offset_of_year + (offset_of_year/4) + (zero_based_cent/4) + 5*zero_based_cent)%7;

	//checking days
	switch (zeller_day){
			case 0:
				printf("It's a Saturday.\n");
				break;
			case 1:
				printf("It's a Sunday.\n");
				break;
			case 2:
				printf("It's a Monday.\n");
				break;
			case 3:
				printf("It's a Tuesday.\n");
				break;
			case 4:
				printf("It's a Wednesday.\n");
				break;
			case 5:
				printf("It's a Thursday.\n");
				break;
			case 6:
				printf("It's a Friday.\n");
				break;
	}
	//checking same dates
	for (year2=year2+1; year2<=endyear; year2++){
		int zero_based_cent = year2/100;
		int offset_of_year = year2%100;
		int new_zeller_day = (day + ((13 * (month + 1))/5) + offset_of_year + (offset_of_year/4) + (zero_based_cent/4) + 5*zero_based_cent)%7;
		if(new_zeller_day == zeller_day){
			counter++;
		}
	}
	printf("Same day-and-month on same weekday between %d and %d: %d\n", year+1, endyear, counter);
	return EXIT_SUCCESS;
}

