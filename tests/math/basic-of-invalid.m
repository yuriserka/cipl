int ;

int redecl(int a) {
    float a;
}

int main() {
    if (1) {
        int i;
    } else {
        i = 2;
    }
}