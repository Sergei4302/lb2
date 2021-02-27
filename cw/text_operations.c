#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include "structs.h"
#include "text_operations.h"

#define BUFF 100
#define mpod "\e[m"
#define none "\x1b[0m"

struct Text get_text(){
    struct Text inp_text;
    int text_buff = BUFF, words_buff = BUFF, sep_buff = BUFF;
    int words_in_sent = 0, letters_in_sent = 0, num_of_sent = 0, letters_in_word = 0;
    wchar_t *word; 
    inp_text.sentences  = malloc(text_buff * sizeof(struct Sentence));
    wchar_t inp_sym;
    int point = 1, flag2 = 1, same = 0;
    while(point == 1){
        inp_sym = getwchar();
        if (inp_sym == L'\n') {
            point = 0;
            break;
        }
        struct Sentence sentence;
        sentence.words = malloc(words_buff * sizeof(wchar_t*));
        sentence.separator = malloc(sep_buff * sizeof(wchar_t));
        sentence.num_of_words = 0;
        while(inp_sym != L'.') {
            word = malloc(words_buff * sizeof(wchar_t));
            while (inp_sym != L' ' && inp_sym != L',' && inp_sym != L'.') { 
                word[letters_in_word] = inp_sym;
                letters_in_word++;
                if (letters_in_word + 5 == words_buff){ 
                    word = realloc(word, words_buff * sizeof(wchar_t));
                    sentence.words = realloc(sentence.words, words_buff  * sizeof(wchar_t*));
                    words_buff += BUFF;
                }
                letters_in_sent++;
                inp_sym = getwchar();
            }
            word[letters_in_word] = L'\0';
            sentence.words[words_in_sent] = word;
            letters_in_word = 0;
            sentence.separator[words_in_sent] = inp_sym;
            if (words_in_sent + 2 == sep_buff){
                sentence.separator = realloc(sentence.separator, sep_buff * sizeof(wchar_t));
                sep_buff += BUFF;
            }
            letters_in_sent++;
            words_in_sent++;
            if (inp_sym != L'.' && inp_sym != L'\n') {
                inp_sym = getwchar();
            }
            else break;
        }
        sentence.num_of_words = words_in_sent;
        words_in_sent = 0;
        flag2 = 0;
        same = 0;
        for (int i = 0; i < num_of_sent; i++){
            struct Sentence prev = inp_text.sentences[i];
            for (int j = 0; j < prev.num_of_words; j++){
                if (prev.num_of_words != sentence.num_of_words)
                    break;
                if (prev.separator[j] == sentence.separator[j])
                    flag2++;
                for (int k = 0; k < wcslen(prev.words[j]); k++)
                    if (towlower(prev.words[j][k]) == towlower(sentence.words[j][k])){
                        flag2++;
                    }
            }
            if (flag2 == letters_in_sent) {
                same = 1;
                break;
            }
            flag2 = 0;
        }
        letters_in_sent = 0;
        if (same == 0) {
            inp_text.sentences[num_of_sent] = sentence;
            num_of_sent++;
            if (num_of_sent + 2 == text_buff) {
                inp_text.sentences = realloc(inp_text.sentences, text_buff * sizeof(struct Sentence));
                text_buff += BUFF;
            }
        }
    }
    inp_text.len_text = num_of_sent;
    return inp_text;
}

void print_text(struct Text inp_text){
    for (int i = 0; i < inp_text.len_text; i++) {
        for (int j = 0; j < inp_text.sentences[i].num_of_words; j++){
            wprintf(mpod none L"%ls%c", inp_text.sentences[i].words[j], inp_text.sentences[i].separator[j]);
        }
    }
    wprintf(L"\n");
}
