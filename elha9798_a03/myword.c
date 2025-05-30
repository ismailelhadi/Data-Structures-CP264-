/*
 * your program signature
 */ 

 #include <stdio.h>
 #include <string.h>
 #include "mystring.h"
 #include "myword.h"
 
 #define MAX_LINE_LEN 1000
 #define MAX_WORDS 1000
 
 
 /**
  *  add your comment
  */
 int create_dictionary(FILE *fp, char *dictionary) {
    char line[1000];
    char delimiters[] = " .,\n\t\r";
    char *token;

    dictionary[0] = '\0';

    int count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        token = strtok(line, delimiters);
        while (token != NULL) {
            str_lower(token);
            str_trim(token);
            strcat(dictionary, token);
            strcat(dictionary, ",");
            token = strtok(NULL, delimiters);
            count++;

        }

    }

    return count;

}
 
 /**
  *  add your comment
  */
 BOOLEAN contain_word(char *dictionary, char *word) {
    if (word == NULL || *word == '\0') {
        return 0;

    }
    char temp[100] = "";
    snprintf(temp, sizeof(temp), ",%s,", word);
    if (strstr(dictionary, temp) != NULL) {
        return TRUE;

    } else {
        return FALSE;

    }

}
 
 /**
  *  add your comment
  */
 WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    WORDSTATS ws = {0};
    char line[MAX_LINE_LEN];
    char *token;
    char delimiters[] = " .,\n\t\r";

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        ws.line_count++;
        str_lower(line);
        token = strtok(line, delimiters);
        while (token != NULL) {
            ws.word_count++;

            if (contain_word(dictionary, token) == FALSE) {
                int j = 0;
                while (j < ws.keyword_count && strcmp(token, words[j].word) != 0) {
                    j++;
                }

                if (j < ws.keyword_count) {
                    words[j].count++;
                } else {
                    strcpy(words[j].word, token);
                    words[j].count = 1;
                    ws.keyword_count++;
                }
            }

            token = strtok(NULL, delimiters);
        }
    }

    return ws;
}