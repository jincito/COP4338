#define _GNU_SOURCE // Enables strdup and strcasecmp on some systems
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10000
#define error(message, code) do { printf("%s\n", message); exit(code); } while(0)

typedef struct node {
    char* string;
    struct node* next;
} node;

typedef struct bucket {
    char* min_word;
    node* head;
} bucket;

void insert_after(node* current, char* new_value) {
    // Insert new_value right after the current node
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node) error("Memory allocation failed", 1);
    new_node->string = strdup(new_value);
    new_node->next = current->next;
    current->next = new_node;
}

void add_to_bucket(bucket* buckets, int bucket_count, char* input_string) {
    // Find the correct bucket for the input string and insert it
    for (int i = bucket_count - 1; i >= 0; i--) {
        if (strcasecmp(input_string, buckets[i].min_word) >= 0) {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->string = strdup(input_string);
            new_node->next = NULL;

            // Insert the new node into the sorted linked list
            if (!buckets[i].head || strcasecmp(input_string, buckets[i].head->string) < 0) {
                new_node->next = buckets[i].head;
                buckets[i].head = new_node;
            } else {
                node* current = buckets[i].head;
                while (current->next && strcasecmp(input_string, current->next->string) >= 0) {
                    current = current->next;
                }
                insert_after(current, input_string);
                free(new_node->string); // Avoid memory duplication
                free(new_node);
            }
            break;
        }
    }
}

void print_buckets(bucket* buckets, int bucket_count) {
    // Print all non-empty buckets
    for (int i = 0; i < bucket_count; i++) {
        if (buckets[i].head != NULL) { // Not empty
            printf("bucket #%d: ", i);
            node* current = buckets[i].head;
            while (current) {
                printf("%s ", current->string);
                current = current->next;
            }
            printf("\n");
        }
    }
}

void free_buckets(bucket* buckets, int bucket_count) {
    // Free memory for all buckets and their linked lists
    for (int i = 0; i < bucket_count; i++) {
        node* current = buckets[i].head;
        while (current) {
            node* temp = current;
            current = current->next;
            free(temp->string);
            free(temp);
        }
        free(buckets[i].min_word);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        error("bucketsort: Too few arguments.", 1);
    }

    bucket* buckets = (bucket*)malloc(argc * sizeof(bucket));
    if (!buckets) error("Memory allocation failed", 1);

    buckets[0].min_word = strdup(""); // Always empty string for the first bucket
    buckets[0].head = NULL;

    for (int i = 1; i < argc; i++) {
        buckets[i].head = NULL; // Initially, all buckets are empty
        buckets[i].min_word = strdup(argv[i]);
        if (!buckets[i].min_word) error("Memory allocation failed", 1);

        if (strcasecmp(buckets[i - 1].min_word, buckets[i].min_word) >= 0)
            error("bucketsort: the CLAs must be alphabetically sorted!", 1);
    }


    // Read input from stdin
    char* line = (char*)malloc(MAX_LEN);
    if (!line) {
        error("Memory allocation error", 2);
    }

    while (fgets(line, MAX_LEN, stdin)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0'; // Remove newline character
        }
        char* input_string = strtok(line, " ");
        while (input_string) {
            add_to_bucket(buckets, argc, input_string);
            input_string = strtok(NULL, " ");
        }
    }

    // Print all non-empty buckets
    print_buckets(buckets, argc);

    // Free allocated memory
    free_buckets(buckets, argc);
    free(line);
    free(buckets);

    return 0;
}