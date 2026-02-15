//Eduardo Maliszewski Goulart

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int compare(char *a, char *b) {
    char ab[25], ba[25];

    sprintf(ab, "%s%s", a, b);
    sprintf(ba, "%s%s", b, a);

    return strcmp(ab, ba); 
    // > 0 ab maior
    // < 0 ba maior
}

void quicksort(char **data, int left, int right) {
    int i = left;
    int j = right;
    char *pivot = data[(left + right) / 2];

    while (i <= j) {

        while (compare(data[i], pivot) > 0)
            i++;

        while (compare(data[j], pivot) < 0)
            j--;

        if (i <= j) {
            swap(&data[i], &data[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(data, left, j);

    if (i < right)
        quicksort(data, i, right);
}

char* largestNumber(int* nums, int numsSize) {

    char **strList = malloc(numsSize * sizeof(char*));

    // Converte a lista nums para uma lista com ponteiros para um espaço com os numeros como string
    for (int i = 0; i < numsSize; i++) {
        strList[i] = malloc(12);
        sprintf(strList[i], "%d", nums[i]);
    }

    //Chama o quicksort para ordenar
    quicksort(strList, 0, numsSize - 1);

    // Caso seja tudo 0 ele tem que colocar só um 0
    if (strcmp(strList[0], "0") == 0) {
        char *res = malloc(2);
        strcpy(res, "0");
        return res;
    }


    // Calcula quantos caracteres tem o número
    int total = 1;
    for (int i = 0; i < numsSize; i++)
        total += strlen(strList[i]);

    char *result = malloc(total);
    result[0] = '\0';

    // Concatena os números e retorna a string única
    for (int i = 0; i < numsSize; i++)
        strcat(result, strList[i]);

    return result;
}
