struct Sentence{
    wchar_t **words;
    wchar_t *separator;
    int num_of_words;
};

struct Text{
    struct Sentence *sentences;
    int len_text;
};
