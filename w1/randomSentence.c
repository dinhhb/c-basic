#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    // Khai báo mảng chứa các từ vựng
    char* articles[] = {"the", "a", "one", "some", "any"};
    char* nouns[] = {"boy", "girl", "dog", "town", "car"};
    char* verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char* prepositions[] = {"to", "from", "over", "under", "on"};

    // Khởi tạo bộ sinh số ngẫu nhiên với thời gian hiện tại
    srand(time(NULL));

    int i;
    for (i = 0; i < 10; i++) {
        // Lựa chọn ngẫu nhiên các từ trong mảng
        int articleIndex = rand() % 5;
        int nounIndex = rand() % 5;
        int verbIndex = rand() % 5;
        int prepositionIndex = rand() % 5;

        printf("%c%s %s %s %s %s.\n", toupper(articles[articleIndex][0]), articles[articleIndex] + 1, nouns[nounIndex], verbs[verbIndex], articles[articleIndex], nouns[nounIndex]);
    }

    return 0;
}
