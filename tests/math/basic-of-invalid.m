int ;

int var_redecl(int a) {
    float a;
    int list a;
    float list a;
    int var_redecl;
}

int param_redecl(int a, float a) {}

int fn_decl() {}
int list fn_decl() {}

int main() {
    if (1) {
        int i;
    } else {
        i = 2;
    }
}