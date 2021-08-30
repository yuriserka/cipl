let global_var;

let filter(integer) {
    return integer <= 10;
}

let map(integer) {
    return integer * 2;
}

let operators() {
    let x;
    let list;
    x = (x || 15) && (x != 4);
    if (x == 10) {
        let x;
        x = 1 > 2 <= 3 >= 0 < -5;
    } else {
        list = (x = +1 + -2 - !(x == 1) * 4 / 5) : list;
        list = filter << (map >> list);
        x = x + -?list;
        let tail;
        tail = !list;
        tail = %list;
    }
}

let conditional(a) {
    if (1) {
        let a;
        a = 7;
    } else {
        a = 2;
        let b;
        b = a + 1;
        return b;
    }
    return 0;
}

let iteration(it, max) {
    let ret;
    ret = 0;
    for (; it < max; it = it + 1) {
        let hi;
        let lo;
        hi = (it * 6);
        lo = (it * 16);
        ret = ret + hi + lo;

        if (ret >= 100000) {
            let error;
            error = ret - (15 - 5);
            return -1;
        }
    }
    return ret;
}

let main(argc, argv) {
    if (argc < 2 + !argv) {
        return 1;
    }

    global_var = 0;
    let i;

    for (i = 2; ; ) {}
    for (; i < 10 ;) {}
    for (;;i = i + 1) {}
    for (;;) {
        let loop;
    }
}
