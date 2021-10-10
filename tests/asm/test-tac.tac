.table

char str_0[] = "'a' antes do assign = "
char str_1[] = "'b' antes do assign = "
char str_2[] = "'a' depois do assign = "
char str_3[] = "'b' depois do assign = "
char snil[] = "nil"

.code

cast_num:
    mov $0, *#0
    mov $1, *#1
    seq $2, $0, $1
    brnz cast_num_EQ
    slt $2, $1, $0
    slt $2, $0, $1
    brnz set_var_val_F2I, $2
    mov $2, $2
    inttofl $2, $2
    jump cast_num_END
set_var_val_F2I:
    mov $2, $2
    fltoint $2, $2
    jump cast_num_END
cast_num_EQ:
    mov $2, #1[1]
cast_num_END:
    mema $3, 2
    mov $3[1], $2
    mov *$3, 1
    return $3

get_var_val:
    mov $0, *#0
    seq $0, $0, 2
    brz get_var_val_INT, $0
    mov $0, #0[1]
    jump get_var_val_END
get_var_val_INT:
    mov $0, #0[1]
get_var_val_END:
    return $0

set_var_val:
    seq $0, #2, 0
    brz set_var_val_FROM_VAR, $0
    mov $0, *#0
    mov $3, 42
    jump set_var_val_END
set_var_val_FROM_VAR:
    mov $0, *#0
    mov $1, *#1
    mov $2, #1[1]
set_var_val_START:
    seq $3, $0, $1
    brnz set_var_val_EQUAL, $3
    slt $3, $0, $1
    brnz set_var_val_F2I, $3
    mov $3, $2
    inttofl $3, $3
    jump set_var_val_END
set_var_val_F2I:
    mov $3, $2
    fltoint $3, $3
    jump set_var_val_END
set_var_val_EQUAL:
    mov $3, $2
set_var_val_END:
    mov #0[1], $3
    return 0

read:
    mov $0, *#0
    seq $0, $0, 2
    brz read_INT, $0
    scanf $1
    jump read_END
read_INT:
    scani $1
read_END:
    mov #0[1], $1
    return 0

write:
    mov $0, #0[0]
    seq $0, $0, 3
    brnz write_STR, $0
    param #0
    call get_var_val, 1
    pop $0
    print $0
    jump write_END
write_STR:
    mov $0, #0[1]
    mov $2, 0
write_STR_LOOP:
    mov $1, '\0'
    mov $3, $0[$2]
    seq $1, $1, $3
    brnz write_END, $1 
    print $3
    add $2, $2, 1
    jump write_STR_LOOP
write_END:
    return 0

writeln:
    param #0
    param #1
    call write, 2
    println
    return 0

func_var_decl:
    // int a
    mema $0, 2
    mov *$0, 1
    mov $0[1], 0

    param $0
    call read, 1

    // float b
    mema $1, 2
    mov *$1, 2
    mov $1[1], 0

    param $1
    call read, 1

    mov $2, &str_0
    param $2
    param 0
    call write, 2

    param $0
    param 2
    call writeln, 2

    mov $2, &str_1
    param $2
    param 0
    call write, 2

    param $1
    param 2
    call writeln, 2

    // assign a = b
    param $0 // lhs
    param $1 // rhs
    param 1
    call set_var_val, 3

    mov $2, &str_2
    param $2
    param 0
    call write, 2
    param $0
    param 2
    call writeln, 2

    mov $2, &str_3
    param $2
    param 0
    call write, 2
    param $1
    param 2
    call writeln, 2

    return 0

func_add:
    // var int a
    mema $0, 2
    mov $0[1], 8
    mov *$0, 1

    // var int b
    mema $1, 2
    mov $1[1], 7
    mov *$1, 1

    // push a onto stack
    push $0

    // push b onto stack
    push $1

    // retrieve a/b from stack
    pop $3
    pop $2

    param $2
    call get_var_val, 1
    pop $4

    param $3
    call get_var_val, 1
    pop $5

    add $5, $4, $5

    // fake return from binary op
    mema $4, 2
    mov *$4, 1
    mov $4[1], $5
    push $4

    return $4

main:
    call func_var_decl, 0
    
    call func_add, 0
    pop $0

    param $0
    param 2
    call writeln, 2

EOF:
    nop
