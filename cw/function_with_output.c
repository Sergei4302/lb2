#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include "structs.h"
#include "function_with_output.h"

#define red "\x1b[31m"
#define none "\x1b[0m"
#define pod "\e[4m"
#define mpod "\e[m"

void function_with_output(struct Text text){
    if (*text.sentences[0].words[text.sentences[0].num_of_words-1] == *text.sentences[text.len_text - 1].words[text.sentences[text.len_text-1].num_of_words-1]) {
        for (int j = 0; j < text.sentences[0].num_of_words; j++) {
            if(j==text.sentences[0].num_of_words-1){
            wprintf(pod red  L"%ls",  text.sentences[0].words[j]);
            wprintf(mpod none  L"%c ",  text.sentences[0].separator[j]);
            }
            else{
                wprintf(L"%ls%c", text.sentences[0].words[j], text.sentences[0].separator[j]);
            }
        }
    }
    for (int i = 0; i <text.len_text-1; i++) { 
      if(*text.sentences[i + 1].words[text.sentences[i + 1].num_of_words - 1] == *text.sentences[i].words[text.sentences[i].num_of_words - 1]){
          for (int j = 0; j < text.sentences[i+1].num_of_words; j++){
              if(j==text.sentences[i+1].num_of_words-1){
                wprintf(pod red L"%ls", text.sentences[i+1].words[j]);
                  wprintf(mpod none L"%c",text.sentences[i+1].separator[j]);
              }
              else{
                  wprintf(L"%ls%c", text.sentences[i+1].words[j], text.sentences[i+1].separator[j]);
              }
          }
      }
    }
    wprintf(mpod none  L"\n");
}
