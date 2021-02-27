#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include "structs.h"
#include "operations_with_offers.h"

void qdelete(struct Text *text, int i){
    for (int j = 0; j < text->sentences[i].num_of_words; ++j) {

        free(text->sentences[i].words[j]);
    }
    free(text->sentences[i].separator);
    for (;i <text->len_text;i++){
        text->sentences[i] = text->sentences[i+1];
    }
    int t = (text->len_text)-1;
    free(text->sentences[t].words);
    free(text->sentences[t].separator);
    text->len_text--;
}
void delete (struct Text text){
    for (int i = 0; i < text.len_text;) {
         if (text.sentences[i].num_of_words<4){
            qdelete(&text, i);
        }
        else i++;
    }
}

void numbers_to_letters(struct Text text){
    for(int i=0; i<text.len_text; i++){
        for(int k=0; k<text.sentences[i].num_of_words; k++){
            int j=wcslen(text.sentences[i].words[k])-1;
            if(text.sentences[i].words[k][j]==L'0'){
                text.sentences[i].words[k][j++]=L'н';
                text.sentences[i].words[k][j++]=L'о';
                text.sentences[i].words[k][j++]=L'л';
                text.sentences[i].words[k][j++]=L'ь';
            }
            else{
                if(text.sentences[i].words[k][j]==L'1'){
                    text.sentences[i].words[k][j++]=L'о';
                    text.sentences[i].words[k][j++]=L'д';
                    text.sentences[i].words[k][j++]=L'и';
                    text.sentences[i].words[k][j++]=L'н';
                }
                else{
                    if(text.sentences[i].words[k][j]==L'2'){
                        text.sentences[i].words[k][j++]=L'д';
                        text.sentences[i].words[k][j++]=L'в';
                        text.sentences[i].words[k][j++]=L'а';
                    }
                    else{
                        if(text.sentences[i].words[k][j]==L'3'){
                            text.sentences[i].words[k][j++]=L'т';
                            text.sentences[i].words[k][j++]=L'р';
                            text.sentences[i].words[k][j++]=L'и';
                        }
                        else{
                            if(text.sentences[i].words[k][j]==L'4'){
                                text.sentences[i].words[k][j++]=L'ч';
                                text.sentences[i].words[k][j++]=L'е';
                                text.sentences[i].words[k][j++]=L'т';
                                text.sentences[i].words[k][j++]=L'ы';
                                text.sentences[i].words[k][j++]=L'р';
                                text.sentences[i].words[k][j++]=L'е';
                            }
                            else{
                                if(text.sentences[i].words[k][j]==L'5'){
                                    text.sentences[i].words[k][j++]=L'п';
                                    text.sentences[i].words[k][j++]=L'я';
                                    text.sentences[i].words[k][j++]=L'т';
                                    text.sentences[i].words[k][j++]=L'ь';
                                }
                                else{
                                    if(text.sentences[i].words[k][j]==L'6'){
                                        text.sentences[i].words[k][j++]=L'ш';
                                        text.sentences[i].words[k][j++]=L'е';
                                        text.sentences[i].words[k][j++]=L'с';
                                        text.sentences[i].words[k][j++]=L'т';
                                        text.sentences[i].words[k][j++]=L'ь';
                                    }
                                    else{
                                        if(text.sentences[i].words[k][j]==L'7'){
                                            text.sentences[i].words[k][j++]=L'с';
                                            text.sentences[i].words[k][j++]=L'е';
                                            text.sentences[i].words[k][j++]=L'м';
                                            text.sentences[i].words[k][j++]=L'ь';
                                        }
                                        else {
                                            if (text.sentences[i].words[k][j] == L'8') {
                                                text.sentences[i].words[k][j++] = L'в';
                                                text.sentences[i].words[k][j++] = L'о';
                                                text.sentences[i].words[k][j++] = L'с';
                                                text.sentences[i].words[k][j++] = L'е';
                                                text.sentences[i].words[k][j++] = L'м';
                                                text.sentences[i].words[k][j++] = L'ь';
                                            }
                                            else {
                                                if (text.sentences[i].words[k][j] == L'9') {
                                                    text.sentences[i].words[k][j++] = L'д';
                                                    text.sentences[i].words[k][j++] = L'е';
                                                    text.sentences[i].words[k][j++] = L'в';
                                                    text.sentences[i].words[k][j++] = L'я';
                                                    text.sentences[i].words[k][j++] = L'т';
                                                    text.sentences[i].words[k][j++] = L'ь';
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                        }

                    }
                }
            }
        }
    }
}
