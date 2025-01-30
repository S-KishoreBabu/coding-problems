void pushmap(int key, int value) {
//     int hashIndex = hashFunction(key);
//     Node *newNode = (Node *) malloc(sizeof(Node));
//     newNode->key = key;
//     newNode->value = value;
//     newNode->next = NULL;

//     if (hashTable[hashIndex] == NULL) {
//         hashTable[hashIndex] = newNode;
//     } else {
//         Node *temp = hashTable[hashIndex];
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }