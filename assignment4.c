#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct instruction_s {
	int step;
	int index;
} instructions[10000];
/*
 * @function get_word
 * @param book the specific line of the book
 * @param n the specific index of the line
 * @result returns a word of nth index from the line *book
 * */
char* get_word(char* book, int n){
	char *word;
	word = (char*) malloc(sizeof(char)*50);
	int i = 0, word_count, k = 0;
	if(book[0] != ' '){
		word_count = 1;
	} else {
		word_count = 0;
	}
	while(book[i] != '\n'){
		
		if(book[i] == ' ' && book[i+1] != ' '){
			word_count++;
		}
		if(word_count == n && !isspace(book[i]) && !ispunct(book[i])){
			*(word+k) = tolower(book[i]);
			k++;
		}
		i++;
	}
	return word;
	free(word);
}
/*
 * @function get_sentence
 * @param **lines the book file itself in 2d array
 * @param instrucions the struct which required lines and indexes are stored
 * @param n_instructions number of instructions
 * @param sentence the array of required words
 * @result concantenates the required words in array sentence
 * */
void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence){
	int step[10000];
	for(int e = 0; e<n_instructions; e++){
		if(e == 0){
			step[e] = instructions[e].step;
		} else {
			step[e] = instructions[e].step + step[e-1];
		}
	}
	for(int ins = 0;ins<n_instructions-1;ins++){
		strcat(sentence, get_word(lines[step[ins]-1], instructions[ins].index));
		strcat(sentence, " ");
	}
}

int main(int argc, char **argv)
{
	FILE *fbook;
	
	//creating a new array of pointers
	char** book = (char**) malloc(10000 * sizeof(char*));
	for (int i = 0; i<10000; i++){
		book[i] = (char*)malloc(200*sizeof(char));
	}
	
	
	//checking for file
	if ((fbook = fopen(argv[1],"r")) == NULL){
	   printf("Error! opening file\n");
	}else{
		//appending the book to the array of pointers 'book'
		for (int a = 0; a<10000; a++){
			fgets(book[a], 200, fbook);	
		}
	}
	
	FILE *fins;
	int operation = 0;
	
	//checking for file
	if ((fins = fopen(argv[2],"r")) == NULL){
	   printf("Error! opening file");
	}else{
		while(!feof(fins)){
			//assigns instructions from the file to instruction_s struct
			fscanf(fins, "%d %d", &instructions[operation].step, &instructions[operation].index);
			operation++;
		}
	}
	
	
	char *sentence = (char*)malloc(sizeof(char)* 200);
	get_sentence(book, instructions, operation, sentence);
	printf("%s", sentence);
	return 0;
	free(sentence);
	for (int z = 0; z < 10000; z++){
		free(book);
	}
}

