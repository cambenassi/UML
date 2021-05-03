char *reverse(char *word) {
    int length = 0;
    char temp;
    
    for (int j = 0; word[j] != '\0'; j++)
        length++;
    
    for (int i = 0; i < length - 1; i++) {
        temp = word[i];
        word[i] = word[length - 1];
        word[length - 1] = temp;
        length--;
    }
    return word;
}