let global_var;

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

// let panic() {
//     writeln("panic! something went wrong\n");
// }

let main(argc, argv) {
    if (argc < 2 + !argv) {
        // panic();
        return 1;
    }

    global_var = 0;
    // conditional(global_var);
    // iteration(it, max);

    let i;
    for (i = 2; ; ) {}
    for (; i < 10 ;)
    for (;;i = i + 1) {}
}