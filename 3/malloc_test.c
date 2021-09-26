//
// Created by Administrator on 2021/9/26.
//

#include <malloc.h>

struct rlimit {
    int rlim_cur;
    int rlim_max;
};

int main() {

    struct rlimit *a = (struct rlimit *) malloc(sizeof(struct rlimit) * 4);
    a->rlim_cur = 12;
    free(a);
}