#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include "structs.h"
#include "function_with_output.h"
#include "operations_with_offers.h"
#include "q_sort.h"
#include "text_operations.h"

int main() {
    setlocale(LC_ALL, "");
    wchar_t command = L'0', space;
    struct Text inp_text;
    wprintf(L"Введите текст\n");
    inp_text = get_text();
    wchar_t key = L'1';
    wprintf(L"Чтобы заменить цифры ,стоящие в конце слова, на буквы, введите  \"1\".\n"
            "Чтобы вывести все предложения в которых на последнем месте, последнее слово, предыдущего предложения, введите \"2\".\n"
            "Чтобы отсортировать предложения по уменьшению количества слов в предложении, введите \"3\".\n"
            "Чтобы удалить все предложения в которых меньше 3 слов, введите\"4\".\n"
            "Чтобы распечатать текст, нажмите \"5\".\n"
            "Для выхода из программы введите любой другой символ.\n"
    );
    while (wcschr(L"12345", key) != NULL) {
        key = fgetwc(stdin);
        fgetwc(stdin);
        switch (key) {
            case L'1':
                numbers_to_letters(inp_text);
                break;
            case L'2':
                function_with_output(inp_text);
                break;
            case L'3':
                q_sort(inp_text);
                break;
            case L'4':
                delete(inp_text);
                break;
            case L'5':
                print_text(inp_text);
                break;
            default:
                wprintf(L"Выход из программы.\n");
                break;
        }
    }
    for (int i = 0; i < inp_text.len_text; i++) {
        free(inp_text.sentences[i].words);
        free(inp_text.sentences[i].separator);
    }
    free(inp_text.sentences);
}
