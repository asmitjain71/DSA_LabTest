#include <stdio.h>

int main() {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);  // Print each line
    }

    fclose(file);
    return 0;
}
