#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_text(const char *filename, const char *old_text, const char *new_text) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *pos = NULL;
        while ((pos = strstr(line, old_text)) != NULL) {
            *pos = '\0';
            printf("%s%s%s", line, new_text, pos + strlen(old_text));
            strcpy(line, pos + strlen(old_text)); // Перемещаемся дальше
        }

    }
    fclose(file);
}

void delete_lines(const char *filename, const char *text_to_delete) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *pos;
        // Ищем в строке вхождение подстроки, которую нужно удалить
        while ((pos = strstr(line, text_to_delete)) != NULL) {
            // Заменяем найденное вхождение на пустую строку
            *pos = '\0';  // обрезаем строку до найденного текста
            strcat(line, pos + strlen(text_to_delete));  // добавляем остаток строки
        }
        // Печатаем строку после удаления
        printf("%s", line);
    }

    fclose(file);
}

void insert_text(const char *filename, const char *insert_text, int position_front) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (position_front) {
            printf("%s%s", insert_text, line); // Вставляем текст в начало строки
        } else {
            line[strcspn(line, "\n")] = '\0'; // Убираем символ новой строки
            printf("%s%s\n", line, insert_text); // Вставляем текст в конец строки
        }
    }
    fclose(file);
}