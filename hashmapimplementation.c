#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10  // Number of buckets in the hashmap

// Structure for key-value pair
typedef struct HashMapNode {
    char key[50];          // Key
    int value;             // Value
    struct HashMapNode* next; // Pointer to the next node (for collision handling)
} HashMapNode;

// Hashmap structure containing an array of linked lists (buckets)
typedef struct HashMap {
    HashMapNode* buckets[HASH_SIZE];
} HashMap;

// Hash function to calculate the index for a given key
unsigned int hashFunction(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++; // Hash function using bit shifting
    }
    return hash % HASH_SIZE; // Return the index based on the size of the array
}

// Create a new hashmap
HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < HASH_SIZE; i++) {
        map->buckets[i] = NULL; // Initialize each bucket as NULL
    }
    return map;
}

// Create a new key-value node
HashMapNode* createNode(const char* key, int value) {
    HashMapNode* node = (HashMapNode*)malloc(sizeof(HashMapNode));
    strcpy(node->key, key);
    node->value = value;
    node->next = NULL;
    return node;
}

// Insert a key-value pair into the hashmap
void insert(HashMap* map, const char* key, int value) {
    unsigned int index = hashFunction(key);
    HashMapNode* newNode = createNode(key, value);
    
    // If no collision, place it in the empty bucket
    if (map->buckets[index] == NULL) {
        map->buckets[index] = newNode;
    } else {
        // If collision occurs, insert at the beginning of the linked list
        newNode->next = map->buckets[index];
        map->buckets[index] = newNode;
    }
}

// Search for a value by key in the hashmap
int search(HashMap* map, const char* key) {
    unsigned int index = hashFunction(key);
    HashMapNode* current = map->buckets[index];
    
    // Traverse the linked list in the corresponding bucket
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Return the value if key is found
        }
        current = current->next;
    }
    return -1; // Return -1 if the key is not found
}

// Delete a key-value pair from the hashmap
void delete(HashMap* map, const char* key) {
    unsigned int index = hashFunction(key);
    HashMapNode* current = map->buckets[index];
    HashMapNode* prev = NULL;
    
    // Traverse the linked list to find the key
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                // Key found at the head of the list
                map->buckets[index] = current->next;
            } else {
                // Key found in the middle or end of the list
                prev->next = current->next;
            }
            free(current); // Free the memory for the node
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key not found!\n");
}

// Function to print the hashmap for debugging purposes
void printHashMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        if (map->buckets[i] != NULL) {
            HashMapNode* current = map->buckets[i];
            printf("Bucket %d: ", i);
            while (current != NULL) {
                printf("(%s, %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

// Free the memory allocated for the hashmap
void freeHashMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashMapNode* current = map->buckets[i];
        while (current != NULL) {
            HashMapNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map); // Free the hashmap itself
}

int main() {
    // Create a hashmap
    HashMap* map = createHashMap();
    
    // Insert some key-value pairs
    insert(map, "apple", 10);
    insert(map, "banana", 20);
    insert(map, "orange", 30);
    insert(map, "grape", 40);
    
    // Print the hashmap
    printf("HashMap after insertion:\n");
    printHashMap(map);
    
    // Search for a value
    int value = search(map, "banana");
    if (value != -1) {
        printf("Found value for key 'banana': %d\n", value);
    } else {
        printf("Key 'banana' not found!\n");
    }
    
    // Delete a key-value pair
    delete(map, "orange");
    printf("HashMap after deleting 'orange':\n");
    printHashMap(map);
    
    // Free the memory used by the hashmap
    freeHashMap(map);
    
    return 0;
}
