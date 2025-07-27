#include <stdio.h>
#include <string.h>

int main() {
    char password_buffer[16];
    char correct_password[] = "mypassword";

    printf("Введите пароль: ");
    scanf("%15s", password_buffer);

    if (strcmp(password_buffer, correct_password) == 0) {
        printf("Correct password!\n");
    } else {
        printf("incorect password!\n");
    }

    return 0;
}
