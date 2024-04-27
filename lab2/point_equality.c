#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

bool arePointsEqual(const Point *p1, const Point *p2) {
    return (p1->x == p2->x) && (p1->y == p2->y);
}

int main() {
    Point point1, point2;

    // Reading the coordinates for the first point
    printf("Enter x and y coordinates for the first point: ");
    scanf("%d %d", &point1.x, &point1.y);

    // Reading the coordinates for the second point
    printf("Enter x and y coordinates for the second point: ");
    scanf("%d %d", &point2.x, &point2.y);

    // Check if the points are equal
    if (arePointsEqual(&point1, &point2)) {
        printf("The two points are equal.\n");
    } else {
        printf("The two points are not equal.\n");
    }

    return 0;
}
