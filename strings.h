#ifndef STRINGS_H
#define STRINGS_H

int str_len(const char* word);
char* str_dup(const char* src);
char* str_concat_new(const char* a, const char* b);
char* str_sub(const char* src, int start, int length);
char* str_repeat(const char* src, int n);

#endif