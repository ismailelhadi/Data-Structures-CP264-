/*
 * your program signature
 */ 
 
 #include "mystring.h"


 /**
  *  add your comment
  */
 int str_words(char *s) {
    if (s == 0) {
		return -1;
	}
	int count = 0;
	char *p = s;
	while (*p) {
		if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
			if (p == s || *(p - 1) == ' ' || *(p - 1) == '\t' || *(p - 1) == ',' || *(p - 1) == '.') {
				count++;
			}
		}
		p++;
	}
	return count;

}
 
 /**
  *  add your comment
  */
 int str_lower(char *s) {
    if (s==0){
		return -1;
	}
	int count = 0 ;
	char *p = s;
	while (*p) {
		if (*p >= 'A' && *p <= 'Z') {
			*p = *p + 32;
			count++;

		}
		p++;
	}
	return count;


}

 
 /**
  *  add your comment
  */
 void str_trim(char *s) {
 char *p = s;
 char *dp = s;

 while (*p) {
     if (*p != ' ' || (p > s && *(p-1) != ' ')) {
         *dp = *p;
         dp++;
     }
     p++;
 }
 if (dp > s && *(dp-1) == ' ') {
     *(dp -1) = '\0';
 } else {
     *dp = '\0';
 }


}