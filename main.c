#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

static void test_strings(void) {
    char* result;

    /* TP2 - Partie A, Q1 : duplication */
    result = str_dup("bonjour");
    assert(result != NULL && str_len(result) == 7);
    printf("str_dup : %s\n", result);
    free(result);

    /* TP2 - Partie A, Q2 : concatenation */
    result = str_concat_new("bon", "jour");
    assert(result != NULL && str_len(result) == 7);
    printf("str_concat_new : %s\n", result);
    free(result);

    /* TP2 - Partie A, Q3 : sous-chaine */
    result = str_sub("bonjour", 3, 20);
    assert(result != NULL && str_len(result) == 4);
    printf("str_sub : %s\n", result);
    free(result);

    result = str_sub("bonjour", -1, 2);
    assert(result != NULL && str_len(result) == 0);
    free(result);

    /* TP2 - Partie A, Q4 : repetition */
    result = str_repeat("ab", 3);
    assert(result != NULL && str_len(result) == 6);
    printf("str_repeat : %s\n", result);
    free(result);

    result = str_repeat("ab", 0);
    assert(result != NULL && str_len(result) == 0);
    free(result);
    printf("Tests de la partie A : OK\n");
}

int main(void) {
    test_strings();
    return 0;
}