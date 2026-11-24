#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);   // & 를 빼면 런타임 에러
    printf("%d\n", a + b);
    return 0;
}