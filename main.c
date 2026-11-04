#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

static void test_strings(void) {
    char buffer[256];
    char parts[6][256];
    char* result;

    /* TP1 - Q1 : longueur */
    assert(str_len("bonjour") == 7);

    /* TP1 - Q3 : comparaison */
    assert(str_equals("bonjour", "bonjour"));
    assert(!str_equals("bonjour", "bonsoir"));

    /* TP1 - Q4 : concatenation dans dest */
    str_concat(buffer, "bon", "jour");
    assert(str_equals(buffer, "bonjour"));

    /* TP1 - Q5 et Q6 : recherche et comptage */
    assert(str_contains("bonjour tout le monde", "tout"));
    assert(!str_contains("bonjour", "soir"));
    assert(str_count_chars("banane", 'a') == 2);

    /* TP1 - Q7 : remplacement d'une sous-chaine */
    str_replace(buffer, "Hello World", "Wor", "Ips");
    assert(str_equals(buffer, "Hello Ipsld"));
    str_replace(buffer, "banane", "an", "x");
    assert(str_equals(buffer, "bxxe"));

    /* TP1 - Q8 : decoupage; Q9 : affichage; Q10 : assemblage */
    int nb_parts = str_split("un,deux,,quatre,", ',', parts, 6);
    assert(nb_parts == 5);
    assert(str_split("un,deux", ',', parts, 1) == -1);
    assert(str_equals(parts[0], "un"));
    assert(str_equals(parts[2], ""));
    assert(str_equals(parts[4], ""));
    print_split(parts, nb_parts);
    str_join(buffer, parts, nb_parts, ",");
    assert(str_equals(buffer, "un,deux,,quatre,"));

    /* TP2 - A1 : duplication. L'appelant libere le resultat. */
    result = str_dup("bonjour");
    assert(result != NULL && str_equals(result, "bonjour"));
    /* TP1 - Q2 : affichage caractere par caractere */
    print_str(result);
    free(result);

    /* TP2 - A2 : concatenation allouee */
    result = str_concat_new("bon", "jour");
    assert(result != NULL && str_equals(result, "bonjour"));
    print_str(result);
    free(result);

    /* TP2 - A3 : extraction d'une sous-chaine */
    result = str_sub("bonjour", 3, 20);
    assert(result != NULL && str_equals(result, "jour"));
    print_str(result);
    free(result);

    result = str_sub("bonjour", -1, 2);
    assert(result != NULL && str_equals(result, ""));
    free(result);

    /* TP2 - A4 : repetition */
    result = str_repeat("ab", 3);
    assert(result != NULL && str_equals(result, "ababab"));
    print_str(result);
    free(result);

    result = str_repeat("ab", 0);
    assert(result != NULL && str_equals(result, ""));
    free(result);
    printf("Tests des chaînes : OK\n");
}

int main(void) {
    test_strings();
    return 0;
}