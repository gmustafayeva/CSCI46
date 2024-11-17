
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s source_file dest_file1 dest_file2\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    FILE *dest_file1 = fopen(argv[2], "w");
    FILE *dest_file2 = fopen(argv[3], "w");

    if (source_file == NULL || dest_file1 == NULL || dest_file2 == NULL) {
        perror("File opening failed");
        return 1;
    }

    char line[1000];  // Assuming lines won't exceed 1000 characters

    int lines_written_to_dest1 = 0;
    int lines_written_to_dest2 = 0;

    while (fgets(line, sizeof(line), source_file) != NULL) {
        // Remove newline character, if present
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
          if (strlen(line) < 20) {
            // Convert to uppercase
            for (size_t i = 0; i < len; i++) {
                line[i] = toupper((unsigned char)line[i]);
            }
            fprintf(dest_file1, "%s\n", line);
            lines_written_to_dest1++;
        } else {
            // Convert to lowercase
            for (size_t i = 0; i < len; i++) {
                line[i] = tolower((unsigned char)line[i]);
            }
            fprintf(dest_file2, "%s\n", line);
            lines_written_to_dest2++;
        }
    }

       fclose(source_file);
    fclose(dest_file1);
    fclose(dest_file2);

    printf("%d lines written to %s\n", lines_written_to_dest1, argv[2]);
    printf("%d lines written to %s\n", lines_written_to_dest2, argv[3]);

    return 0;
}