#include <stdio.h> // printf, scanf
/*
  Tracking the game score of a dart player.
*/

/*
 * @function PointCalculator
 * @param point Point that dart landed on
 * @param type Type that dart landed on
 * @result calculates the dart point
 * 
 * */
double PointCalculator(int point, char type){
	double sum = 0;
	if (type == 'S'){
		sum = point;
	} else if (type == 'D'){
		sum = point * 2;
	} else if (type == 'T'){
		sum = point * 3;
	} else if (type == 'O'){
		sum = 25;
	} else if (type == 'I'){
		sum = 50;
	}
	return sum;
}
/*
 * @function CurrentPOint
 * @param total The target score
 * @param point Point that dart landed on
 * @param type Type that dart landed on
 * @result Substracts the point from the target
 * */
double CurrentPoint(double total, double point, char type){
		return total = total - PointCalculator(point, type);
	}

int main(){
	double total_score, score;
	char segment;
	printf("Target: ");
	scanf("%lf", &total_score);
	//Loop for the first double
	do {
		printf("Throw: ");
		scanf("%lf %c",&score, &segment);
		if(segment != 'D'){
			printf("Points: %.0lf\n", total_score);
		} else {
			printf("Points: %.0lf\n", CurrentPoint(total_score, score, segment));
		}
	}while(segment != 'D');
	total_score = CurrentPoint(total_score, score, segment);
	//Loop for the other throws until it gets zero
	while(1){
		printf("Throw: ");
		scanf("%lf %c",&score, &segment);
		if(CurrentPoint(total_score, score, segment) > 1){
			total_score = CurrentPoint(total_score, score, segment);	
			printf("Points: %.0lf\n", total_score);
		} else if(CurrentPoint(total_score, score, segment <= 1)){
			if(segment == 'D' && CurrentPoint(total_score, score, segment) == 0){
				printf("Points: %.0lf\n", CurrentPoint(total_score, score, segment));
				break;
			} else {
				printf("Points: %.0lf\n", total_score);
			}
		}
	}
	return 0;
}
