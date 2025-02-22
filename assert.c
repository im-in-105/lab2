#include <stdio.h>
#include <stdlib.h>

void my_assert(int a, const char *message);

void my_assert(int a, const char *message) {
    if (!a) {
        fprintf(stderr, "failed: %s\n", message);
        exit(1);
    }
}

void foo(int num) {

    my_assert((num >= 0 && num <= 100), "failed");

    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]) {
    int num;

    if (argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
}
