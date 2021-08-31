int global_var;

int filter(integer) {
    return integer <= 10;
}

int map(integer) {
    return integer * 2;
}

int operators() {
    int x;
    int list l;
    x = (x || 15) && (x != 4);
    if (x == 10) {
        int x;
        x = 1 > 2 <= 3 >= 0 < -5;
    } else {
        l = 3 : 2 : (+1 + -2 - !(x == 1) * 4 / 5) : l;
        l = filter << (map >> l);
        x = x + -?l;
        float list tail;
        tail = !l;
        tail = %l;
    }
}

int list conditional(a) {
    if (1) {
        float a;
        a = 7.5234;
    } else {
        a = 2;
        float b;
        b = a + 2.72 + 3.14159;
        return b;
    }
    return 0;
}

float list iteration(it, max) {
    int ret;
    ret = 0;
    for (; it < max; it = it + 1) {
        int hi;
        int lo;
        hi = (it * 6);
        lo = (it * 16);
        ret = ret + hi + lo;

        if (ret >= 100000) {
            int error;
            error = ret - (15 - 5);
            return -1;
        }
    }
    return ret;
}

int main(argc, argv) {
    if (argc < 2 + !argv) {
        return 1;
    }

    global_var = 0;
    int i;

    for (i = 2; ; ) {
        int scope_3;
    }
    for (; i < 10 ;) {
        int scope_4;
    }
    int scope_1;
    for (;;i = i + 1) {
        int scope_5;
    }
    for (;;) {
        int loop_6;
    }

    int ret;
    ret = conditional(iteration(i, 15));

    return ret;
}
