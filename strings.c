#include <stdlib.h>
#include "strings.h"
/* TP1 - Q1 : longueur d'une chaine */
int str_len(const char* word) {
    int count = 0;
    if (word == NULL) {
        return 0;
    }
    while (word[count] != '\0') {
        count++;
    }
    return count;
}
/* TP2 - Partie A, Q1 : duplication allouee */
char* str_dup(const char* src) {
    if (src == NULL) {
        return NULL;
    }
    int len = str_len(src);
    char* dup = malloc((len + 1) * sizeof(char));
    if (dup == NULL) {
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        dup[i] = src[i];
    }
    return dup;
}
/* TP2 - Partie A, Q2 : concatenation allouee */
char* str_concat_new(const char* a, const char* b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    int len_a = str_len(a), len_b = str_len(b);
    char* result = malloc((len_a + len_b + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    int i = 0;
    for (int j = 0; j < len_a; j++) {
        result[i++] = a[j];
    }
    for (int j = 0; j < len_b; j++) {
        result[i++] = b[j];
    }
    result[i] = '\0';
    return result;
}
/* TP2 - Partie A, Q3 : extraction allouee */
char* str_sub(const char* src, int start, int length) {
    if (src == NULL) {
        return NULL;
    }
    int len_src = str_len(src);
    if (start < 0 || start >= len_src || length <= 0) {
        char* empty = malloc(sizeof(char));
        if (empty != NULL) {
            empty[0] = '\0';
        }
        return empty;
    }
    if (length > len_src - start) {
        length = len_src - start;
    }
    char* sub = malloc((length + 1) * sizeof(char));
    if (sub == NULL) return NULL;
    for (int i = 0; i < length; i++) {
        sub[i] = src[start + i];
    }
    sub[length] = '\0';
    return sub;
}
/* TP2 - Partie A, Q4 : repetition allouee */
char* str_repeat(const char* src, int n) {
    if (src == NULL) {
        return NULL;
    }
    int len = str_len(src);
    if (n <= 0) {
        char* empty = malloc(sizeof(char));
        if (empty != NULL) {
            empty[0] = '\0';
        }
        return empty;
    }
    char* result = malloc((len * n + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            result[index++] = src[j];
        }
    }
    result[index] = '\0';
    return result;
}