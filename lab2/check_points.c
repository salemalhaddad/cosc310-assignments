#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

bool arePointsEqual(const Point *p1, const Point *p2) {
    return (p1->x == p2->x) && (p1->y == p2->y);
}

bool hasEqualPoints(Point points[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arePointsEqual(&points[i], &points[j])) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: <program> <size>\n");
        return 1;
    }

    int size = atoi(argv[1]);
    Point points[size];

    printf("Enter points (x y):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    if (hasEqualPoints(points, size)) {
        printf("Array contains two equal points.\n");
    } else {
        printf("No two equal points in the array.\n");
    }

    return 0;
}
