#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int width;
    int height;
    int length;
} Cuboid;

void ScaleCuboid(int a, Cuboid *c) {
    c->width *= a;
    c->height *= a;
    c->length *= a;
}

int ComputeArea(Cuboid c) {
    return 2 * (c.height * c.width) + 2 * (c.height * c.length) + 2 * (c.width * c.length);
}

int ComputeVolume(Cuboid c) {
    return c.height * c.width * c.length;
}

bool isCube(Cuboid c) {
    return (c.height == c.width) && (c.width == c.length);
}

int main() {
    Cuboid myCuboid = {2, 3, 4};

    printf("Initial Cuboid Dimensions: Width: %d, Height: %d, Length: %d\n", myCuboid.width, myCuboid.height, myCuboid.length);

    ScaleCuboid(2, &myCuboid); // Scaling the cuboid dimensions
    printf("Scaled Cuboid Dimensions: Width: %d, Height: %d, Length: %d\n", myCuboid.width, myCuboid.height, myCuboid.length);

    printf("Surface Area of the Cuboid: %d\n", ComputeArea(myCuboid));
    printf("Volume of the Cuboid: %d\n", ComputeVolume(myCuboid));

    if (isCube(myCuboid)) {
        printf("The Cuboid is a cube.\n");
    } else {
        printf("The Cuboid is not a cube.\n");
    }

    return 0;
} 
