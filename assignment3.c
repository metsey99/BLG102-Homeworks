#include <stdio.h>
#define CAP 50
/*
 * @function absolute_val
 * @param a first number
 * @param b second number
 * @result calculates the absolute value of the difference between a and b
 * 
 * */
int absolute_val(int a, int b){
	if((a-b) < 0){
		return b-a;
	} else {
		return a-b;
	}
}

/*
 * @function manhattan_distance
 * @param x1 initial x
 * @param y1 initial y
 * @param x2 final x
 * @param y2 final y
 * @result calculates the manhattan distance
 * 
 * */
int manhattan_distance(int x1, int y1, int x2, int y2){
	return absolute_val(x2, x1)+absolute_val(y2, y1);
}

int main() {
	int size, cars;
	
	//checking the size of the parking lot
	do{
	printf("Size: ");
	scanf("%d", &size);
	if(size >= 51){
		printf("Size must be between 50 and 1\n");
	}
	} while(size >= 51);
	
	printf("Cars: ");
	scanf("%d", &cars);
	
	//if there is no cars
	if(cars == 0){
		printf("Best Slot Found In: 1 1\n");
		return 0;
	}
	
	//if the parking lot is full
	if(cars >= size*size){
		printf("Best Slot Found In: 0 0\n");
		return 0;
	}
	if(size == 1 && cars == 1){
		printf("Best Slot Found In: 0 0\n");
		return 0;
	}
	int grid[CAP][CAP] = {};
	int xs[CAP] = {}, ys[CAP] = {};
	int x, y, newmin = 2500, newx, newy;
	int largest_y = 50, largest_x = 50, distance;
	int newmax = 0;
	
	//taking the locations of cars from the user
	for(int m = 0; m<cars; m++){
		printf("Locations: ");
		scanf("%d %d", &x, &y);
		if (x <= size && y <= size){
			xs[m] = x;
			ys[m] = y;
		}else{
			break;
		}
		grid[size - y][x-1]++;
		
	}
	//checking all the distances with 
	for(int i = 0; i<size; i++){  // y axis
		for(int n = 0; n<size; n++){ // x axis
			for(int q = 0; q<cars; q++){ // checking cars array
				distance = manhattan_distance(i+1, n+1, xs[q], ys[q]);
				if(distance < newmin){
						newmin = distance;
						newx = i+1;
						newy = n+1;
				}
			} 
			if(newmin > newmax){
				largest_x = newx;
				largest_y = newy;
				newmax = newmin;
			}	
			newmin = 2500;
		}
	}
	printf("Best Slot Found In: %d %d\n", largest_x, largest_y);
	return 0;
}
