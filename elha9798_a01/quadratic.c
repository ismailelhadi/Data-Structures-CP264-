/*
 * your program signature
 */ 

 #include "quadratic.h"
 #include <math.h>
 #define EPSILON 1e-6
 
 int solution_type(float a, float b, float c)
 {
    if (a == 0) {
        return 0;
    }

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        return 2;
    } else if (discriminant == 0) {
        return 1;
    } else {
        return 3;
    }
}
 
 float real_root_big(float a, float b, float c)
 {
    if (a == 0) {
        return 0;
    }

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return 0;
    }

    if (discriminant == 0) {
        return -b / (2 * a);
    }

    float root1 = (-b + sqrt(discriminant)) / (2 * a);
    float root2 = (-b - sqrt(discriminant)) / (2 * a);
    return root1 > root2 ? root1 : root2;
 }
 
 float real_root_small(float a, float b, float c)
 {
    if (a == 0) {
        return 0.0;
    }

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return 0.0;
    }

    if (discriminant == 0) {
        return -b / (2 * a);
    }

    float root1 = (-b + sqrt(discriminant)) / (2 * a);
    float root2 = (-b - sqrt(discriminant)) / (2 * a);
    return root1 < root2 ? root1 : root2;

 }