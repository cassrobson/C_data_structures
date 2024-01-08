/*
 -------------------------------------
 File:    myrecord.c
 Project: robs7000_a4
 file description
 -------------------------------------
 Author:  Cassel Robson
 ID:      210507000
 Email:   robs7000@mylaurier.ca
 Version  2023-02-09
 -------------------------------------
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"


#define MAX_LINE 100


char letter_grade(float s) {

	//declare letter grades and grade ranges
	char g[] = { 'S', 'A', 'B', 'C', 'D', 'F' };
	float b[] = { 100, 90, 80, 70, 60, 50, 0 };
	//declare linear search variables
	char r = 'S';
	int i = 0;
	int n = sizeof(b) / sizeof(float);
	while (i < n - 1) {
		if ((i == 0 || s < b[i]) && s >= b[i + 1]) {
			r = g[i];
			break;
		}
		i++;
	}


	return r;
}
/*
 This function takes the RECORD array passed by records and the number of record count as input, computes the average score, standard deviation, median of the score values of the record data, and returns the results in STATS type.
 */
STATS process_data(RECORD *dataset, int n) {

	STATS stats = { };
	stats.count = n;
	int count = n;
	float mean = 0;
	float std = 0;
	float median;
	float scores[MAX_LINE];

	// compute mean
	for (int i = 0; i < count; i++) {
		mean += dataset[i].score;
		// add to scores list to calculate median
		scores[i] = dataset[i].score;
	}
	mean /= count;
	stats.mean = mean;

	// compute standard deviation
	for (int i = 0; i < count; i++) {
		std += (dataset[i].score - mean) * (dataset[i].score - mean);
	}
	std = sqrtf(std / count);
	stats.stddev = std;

	// compute the median
	quick_sort(scores, 0, count - 1);
	if (n % 2 != 0) {
		median = scores[(count / 2) - 1];
	} else {
		median = (scores[(count / 2) - 1] + scores[count / 2]) / 2;
	}
	stats.median = median;
	return stats;
}

/*
 This function imports record data from file of name passed by infilename, and retrieves and stores all record entries in the RECORD array passed by records, and returns the number of record count.
 */
int import_data(char *infilename, RECORD *records) {
	FILE *fp = fopen(infilename, "r");
	char delimiters[] = ",\n\r";
	char line[100];
	int i = 0; // record counter
	char *token = NULL;
	while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char*) strtok(line, delimiters);
		strcpy(records[i].name, token); // copy string char array
		token = (char*) strtok(NULL, delimiters);
		records[i].score = atof(token); // convert string to float
		i++;
	}


	return i;
}
/*
 This function takes output file name passed by outfilename, RECORD array passed by records, and STATS value passed by stats, and output stats information, and processed record data to files in required format. It returns 0 if all operations are successful, otherwise 0.
 */
int report_data(char *outfilename, RECORD *records, STATS stats) {
	int count = stats.count;
	FILE *fp = fopen(outfilename, "w");

	fprintf(fp, "stats:value\n");
	fprintf(fp, "count:%d\n", stats.count);
	fprintf(fp, "mean:%.1f\n", stats.mean);
	fprintf(fp, "stddev:%.1f\n", stats.stddev);
	fprintf(fp, "median:%.1f\n", stats.median);

	fprintf(fp, "\nname:score,grade\n");
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s:%.1f,%c\n", records[i].name, records[i].score,
				letter_grade(records[i].score));

	}
	fclose(fp);
	return 0;
}

