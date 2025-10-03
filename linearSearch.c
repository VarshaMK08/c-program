#include <stdio.h>

int main() {
    int key, i, n, a[10], *p, found = 0, pos = -1;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the key element to be found: ");
    scanf("%d", &key);

    p = a;  // pointer to first element
    for (i = 0; i < n; i++) {
        if (key == *p) {
            found = 1;
            pos = i;   // store position
            break;     // stop once found
        }
        p++;   // move pointer to next element
    }

    if (found)
        printf("Key is found at position %d (index %d)\n", pos + 1, pos);
    else
        printf("Key is not found\n");

    return 0;
}
