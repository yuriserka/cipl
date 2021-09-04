int global_var;

int filter(int integer) {
    return integer <= 10;
}

float map(int integer) {
    return integer * 2.0;
}

int operators(int list l) {
    int x;
    x = (x || 15) && (x != 4);
    if (x == 10) {
        int x;
        x = 1 > 2 <= 3 >= 0 < -5;
    } else {
        l = 3 : 2 : (+1 + -2 - !(x == 1) * 4 / 5) : l;
        l = filter << map >> l;
        x = x + -?l;
        float list tail;
        tail = NIL;
        tail = !l;
        tail = %l;
    }
}

int list conditional(float list a) {
    if (1) {
        float a;
        a = 7.5234;
    } else {
        a = 2 : a;
        float b;
        b = ?a + 2.72 + 3.14159;
        return b;
    }
    return 0;
}

float list iteration(int it, int max) {
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

int test_inner_scopes() {
    float scope_one;
    {
        float list scope_two;
        {
            int list scope_three;
        }
        int after_three;
    }
    float after_two;
}

int test_builtin() {
    float nota1;
    float nota2;
    float media;

    write("Digite a primeira nota do aluno: ");
    read(nota1);

    write("Digite a segunda nota do aluno: ");
    read(nota2);

    media = (nota1 + nota2) / 2;

    write("Media do aluno = ");
    writeln(media);

    if (media >= 9.0) {
        writeln("SS");
    } else {
        if (media >= 7.0) {
            writeln("MS");
        } else {
            if (media >= 5.0) {
                writeln("MM");
            } else {
                writeln("--Reprovado--");
            }
        }
    }

    writeln((media + nota1 + nota2) / 3);
}

int scopes_redecl(int a) { // s1-p:0
    { // s2-p:1
        int a;
        { // s3-p:2
            int a;
            if (a) { // s4-p:3
                int a;
            } else { // s5-p:3
                int b;
                a = 2;
                for (a = a + 2;;) { // s6-p:5
                    int a;
                }
            }
        }
    }
    a = 1;
    { // s:7-p:1
        int list a;
        a = 2 : a;
    }
    a = 11;
    { // s:8-p:1
        float a;
        a = 3;
        { // s:9-p:8
            float list a;
            a = 4.0 : a;
        }
        a = 33;
    }
    a = 111;
}

int main(int argc, int argv) {
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

    test_builtin();
    scopes_redecl(ret);

    return ret;
}
