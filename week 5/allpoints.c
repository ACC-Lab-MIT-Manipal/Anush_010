#include <stdio.h>
#include <stdbool.h>

// Define the coefficients of the elliptic curve equation: y^2 = x^3 + ax + b
#define A 1
#define B 1

// Define the prime number for the finite field
#define P 13

// Define a structure to represent a point on the elliptic curve
typedef struct {
    int x, y;
} Point;

// Function to check if a point is on the elliptic curve
bool isPointOnCurve(Point point) {
    int left = (point.y * point.y) % P;
    int right = ((point.x * point.x * point.x) + (A * point.x) + B) % P;
    return (left == right);
}

int main() {
    printf("Points on the elliptic curve y^2 = x^3 + %dx + %d (mod %d):\n", A, B, P);

    for (int x = 0; x < P; x++) {
        for (int y = 0; y < P; y++) {
            Point point = {x, y};
            if (isPointOnCurve(point)) {
                printf("(%d, %d)\n", point.x, point.y);
            }
        }
    }

    return 0;
}
