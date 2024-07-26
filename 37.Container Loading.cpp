#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int width;
    int height;
    int length;
} Item;

// Structure to represent a container
typedef struct {
    int width;
    int height;
    int length;
} Container;

// Function to calculate the volume of an item
int itemVolume(Item item) {
    return item.width * item.height * item.length;
}

// Function to calculate the volume of a container
int containerVolume(Container container) {
    return container.width * container.height * container.length;
}

// Function to compute the total wasted space
int computeWastedSpace(Container container, Item items[], int numItems) {
    int totalVolume = containerVolume(container);
    int usedVolume = 0;

    for (int i = 0; i < numItems; i++) {
        usedVolume += itemVolume(items[i]);
    }

    return totalVolume - usedVolume;
}

int main() {
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    Item *items = (Item *)malloc(numItems * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter dimensions of each item (width height length):\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d %d", &items[i].width, &items[i].height, &items[i].length);
    }

    Container container;
    printf("Enter dimensions of the container (width height length): ");
    scanf("%d %d %d", &container.width, &container.height, &container.length);

    int wastedSpace = computeWastedSpace(container, items, numItems);
    printf("Total wasted space: %d\n", wastedSpace);

    free(items);

    return 0;
}

