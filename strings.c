#include <stdio.h>
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

/* TP1 - Q2 : affichage d'une chaine */
void print_str(const char* word) {
    if (word == NULL) {
        return;
    }
    for (int i = 0; word[i] != '\0'; i++) {
        printf("%c\n", word[i]);
    }
}

/* TP1 - Q3 : comparaison de deux chaines */
int str_equals(const char* a, const char* b) {
    if (a == NULL || b == NULL) {
        return a == b;
    }
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }
    return a[i] == b[i];
}

/* TP1 - Q4 : concatenation dans un tampon fourni */
void str_concat(char* dest, const char* a, const char* b) {
    int i = 0;
    if (dest == NULL || a == NULL || b == NULL) {
        return;
    }
    for (int j = 0; a[j] != '\0'; j++) {
        dest[i++] = a[j];
    }
    for (int j = 0; b[j] != '\0'; j++) {
        dest[i++] = b[j];
    }
    dest[i] = '\0';
}

/* TP1 - Q5 : recherche d'une sous-chaine */
int str_contains(const char* haystack, const char* needle) {
    if (haystack == NULL || needle == NULL) {
        return 0;
    }
    if (needle[0] == '\0') {
        return 1;
    }
    for (int i = 0; haystack[i] != '\0'; i++) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

/* TP1 - Q6 : comptage d'un caractere */
int str_count_chars(const char* s, char c) {
    int count = 0;
    if (s == NULL) {
        return 0;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            count++;
        }
    }
    return count;
}

/* TP1 - Q7 : remplacement d'une sous-chaine */
void str_replace(char* dest, const char* src, const char* from, const char* to) {
    if (dest == NULL || src == NULL || from == NULL || to == NULL) {
        return;
    }
    int from_length = str_len(from);
    int i = 0;
    int j = 0;
    while (src[i] != '\0') {
        int matches = from_length > 0;
        for (int k = 0; k < from_length; k++) {
            if (src[i + k] == '\0' || src[i + k] != from[k]) {
                matches = 0;
                break;
            }
        }
        if (matches) {
            for (int k = 0; to[k] != '\0'; k++) {
                dest[j++] = to[k];
            }
            i += from_length;
        } else {
            dest[j++] = src[i++];
        }
    }
    dest[j] = '\0';
}

/* TP1 - Q8 : decoupage selon un separateur */
int str_split(const char* s, char sep, char parts[][256], int max_parts) {
    if (s == NULL || parts == NULL || max_parts <= 0) {
        return -1;
    }
    int expected = str_count_chars(s, sep) + 1;
    if (expected > max_parts) {
        return -1;
    }

    int length = 0;
    for (int i = 0; ; i++) {
        if (s[i] == sep || s[i] == '\0') {
            if (length >= 256) {
                return -1;
            }
            length = 0;
            if (s[i] == '\0') {
                break;
            }
        } else {
            length++;
        }
    }

    int part = 0;
    int start = 0;
    for (int i = 0; ; i++) {
        if (s[i] == sep || s[i] == '\0') {
            int j = 0;
            while (start + j < i) {
                parts[part][j] = s[start + j];
                j++;
            }
            parts[part][j] = '\0';
            part++;
            start = i + 1;
            if (s[i] == '\0') {
                break;
            }
        }
    }
    return part;
}

/* TP1 - Q9 : affichage des morceaux */
void print_split(const char parts[][256], int nb_parts) {
    if (parts == NULL || nb_parts < 0) {
        return;
    }
    for (int i = 0; i < nb_parts; i++) {
        print_str(parts[i]);
        putchar('\n');
    }
}

/* TP1 - Q10 : assemblage des morceaux */
void str_join(char* dest, char parts[][256], int nb_parts, const char* sep) {
    if (dest == NULL || parts == NULL || nb_parts < 0) {
        return;
    }
    if (sep == NULL) {
        sep = "";
    }
    int index = 0;
    int sep_length = str_len(sep);
    for (int i = 0; i < nb_parts; i++) {
        for (int j = 0; parts[i][j] != '\0'; j++) {
            dest[index++] = parts[i][j];
        }
        if (i < nb_parts - 1) {
            for (int j = 0; j < sep_length; j++) {
                dest[index++] = sep[j];
            }
        }
    }
    dest[index] = '\0';
}

/* TP2 - Partie A, Q1 : duplication allouee */
char* str_dup(const char* src) {
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
    int len_a = str_len(a);
    int len_b = str_len(b);
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
    if (sub == NULL) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        sub[i] = src[start + i];
    }
    sub[length] = '\0';
    return sub;
}

/* TP2 - Partie A, Q4 : repetition allouee */
char* str_repeat(const char* src, int n) {
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