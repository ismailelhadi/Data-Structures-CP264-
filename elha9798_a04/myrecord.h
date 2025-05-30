#ifndef MYRECORD_H
#define MYRECORD_H

#include <stdio.h>

// Structure to hold a person's name and score
typedef struct {
    char name[21];  // Name of the person
    float score;    // Score as a floating point number
} RECORD;

// Structure to hold calculated statistics
typedef struct {
    int count;      // Number of records
    float mean;     // Average score
    float stddev;   // Standard deviation of scores
    float median;   // Median score
} STATS;

// Structure to hold letter grades
typedef struct {
    char letter_grade[3];  // 2 letters + null terminator for grades like A+, B-
} GRADE;

// Function prototypes
GRADE grade(float score);
int import_data(FILE *fp, RECORD *dataset);
STATS process_data(RECORD *dataset, int count);
int report_data(FILE *fp, RECORD *dataset, STATS stats);

#endif // MYRECORD_H
