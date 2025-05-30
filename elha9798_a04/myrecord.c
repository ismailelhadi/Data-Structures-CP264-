#include "myrecord.h"
#include "mysort.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function to convert numerical score to letter grade
GRADE grade(float score) {
    GRADE result;
    if (score >= 90) strcpy(result.letter_grade, score >= 95 ? "A+" : "A");
    else if (score >= 85 && score < 90) strcpy(result.letter_grade, "A-");
    else if (score >= 80 && score < 85) strcpy(result.letter_grade, "B+");
    else if (score >= 77 && score < 80) strcpy(result.letter_grade, "B");
    else if (score >= 73 && score < 77) strcpy(result.letter_grade, "B-");
    else if (score >= 70 && score < 73) strcpy(result.letter_grade, "C+");
    else if (score >= 67 && score < 70) strcpy(result.letter_grade, "C");
    else if (score >= 63 && score < 67) strcpy(result.letter_grade, "C-");
    else if (score >= 60 && score < 63) strcpy(result.letter_grade, "D+");
    else if (score >= 57 && score < 60) strcpy(result.letter_grade, "D");
    else if (score >= 53 && score < 57) strcpy(result.letter_grade, "D-");
    else strcpy(result.letter_grade, "F");
    return result;
}

// Function to import data from a file
int import_data(FILE *fp, RECORD *dataset) {
    char buffer[256];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (2 == sscanf(buffer, "%20[^,],%f", dataset[count].name, &dataset[count].score)) {
            count++;
        }
    }
    return count;
}

// Function to process data and compute statistics


STATS process_data(RECORD *dataset, int count) {
    STATS stats = {0, 0, 0, 0};
    float sum = 0, sum_sq = 0;
    for (int i = 0; i < count; i++) {
        sum += dataset[i].score;
        sum_sq += dataset[i].score * dataset[i].score;
    }
    stats.count = count;
    stats.mean = sum / count;
    float mean_sq = sum_sq / count;
    stats.stddev = sqrt(mean_sq - (stats.mean * stats.mean));
    
    // Sort data for median
    my_sort((void**)dataset, 0, count - 1, default_compare);
    stats.median = (count % 2 == 0) ? 
                   (dataset[count / 2 - 1].score + dataset[count / 2].score) / 2.0 : 
                   dataset[count / 2].score;
    return stats;
}

// Function to report data in a file
int report_data(FILE *fp, RECORD *dataset, STATS stats) {
    if (!fp || stats.count < 1) return 0;
    fprintf(fp, "Stats:value\nCount:%d\nMean:%.1f\nStddev:%.1f\nMedian:%.1f\n\n", stats.count, stats.mean, stats.stddev, stats.median);
    fprintf(fp, "Name:Score,Grade\n");
    for (int i = 0; i < stats.count; i++) {
        GRADE g = grade(dataset[i].score);
        fprintf(fp, "%s:%.1f,%s\n", dataset[i].name, dataset[i].score, g.letter_grade);
    }
    return 1;
}
