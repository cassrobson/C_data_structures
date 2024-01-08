/*
 -------------------------------------
 File:    mystring.c
 Project: cp264_a3
 file description
 - string functinos
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-03
 -------------------------------------
 */
 
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"


int process_word(char *filename, WORD *words, WORDSTATS *wordstats) {
    const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
    char line[MAX_LINE_LEN];
    char *word_token = NULL; int j;
    FILE *fp = fopen(filename, "r");
    while (fgets(line, MAX_LINE_LEN, fp) != NULL){//traverse all lines in the file
        wordstats->line_count++;
        lower_case(line);
        str_trim(line);
        word_token = (char *) strtok(line, delimiters); //the first word
        while (word_token != NULL){ //traverse all words in a line
            wordstats->total_word_count++;
            j = 0;
            while (j < wordstats->distinct_word_count && strcmp(word_token, words[j].word) != 0) j++;{
                if (j < wordstats->distinct_word_count){
                    words[j].frequency++;
                }
                else {
                    strcpy(words[j].word, word_token);
                    words[j].frequency = 1;
                    wordstats->distinct_word_count++;
                }
                 
            }
            word_token = (char*) strtok(NULL, delimiters);//next word
        }

    }
   fclose(fp);
   return 0;
}

int save_file(char *filename, WORD *words, WORDSTATS *wordstats) {
	FILE *fp = fopen(filename, "w");
	// print to file the word stats info
	fprintf(fp, "%s:%s\n", "word stats", "value");
	fprintf(fp, "%s:%d\n", "line count", wordstats->line_count);
	fprintf(fp, "%s:%d\n", "total word count", wordstats->total_word_count);
	fprintf(fp, "%s:%d\n", "distinct word count", wordstats->distinct_word_count);
	// traverse words[] print to file the word and frequency
	fprintf(fp, "\n%s:%s\n", "distinct words", "frequency");
	for (int i = 0; i < wordstats->distinct_word_count; i++) {
		fprintf(fp, "%s:%d\n", words[i].word, words[i].frequency);
	}

	fclose(fp);
	return 0;
}
