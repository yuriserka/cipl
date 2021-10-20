.table

char str_0[] = "'a' antes do assign = "
char str_1[] = "'b' antes do assign = "
char str_2[] = "'a' depois do assign = "
char str_3[] = "'b' depois do assign = "
char snil[] = "nil"

.code

cast:
    seq $0, #1, 1
    brnz cast_F2I, $0
cast_I2F:
    mov $1, 2
    mov $2, #0[1]
    inttofl $2, $2
    jump cast_END
cast_F2I:
    mov $1, 1
    mov $2, #0[1]
    fltoint $2, $2
cast_END:
    mema $3, 2
    mov $3[0], $1
    mov $3[1], $2
    return $3

set_var_val:
    mov $0, #1[0]
    slt $0, $0, 3
    brz set_var_val_LIST, $0
set_var_val_NUMBER:
    mov $0, #1[1]
    mov #0[1], $0
jump set_var_val_END
    set_var_val_LIST:
    mov $0, #1[1]
    mov #0[1], $0
    mov $0, 0
set_var_val_LIST_LOOP:
    mov $1, #0[1]
    slt $1, $0, $1
    set_var_val_END:
    return

get_var_val:
    mov $0, #0[0]
    slt $0, $0, 3
    brz get_var_val_LIST, $0
    mov $0, #0[1]
    jump get_var_val_END
    get_var_val_LIST:
    mov $0, #0[2]
get_var_val_END:
    return $0

sign_change:
    mov $0, #0[1]
    mov $1, #0[0]
    seq $1, $1, 1
    brnz sign_change_INT, $1
sign_change_FLOAT:
    seq $1, #1, '-'
    brnz sign_change_FLOAT_FLIP, $1
    slt $1, $0, 0.0
    brz sign_change_END, $1
sign_change_FLOAT_FLIP:
    mul $0, $0, -1.0
    jump sign_change_END
sign_change_INT:
    seq $1, #1, '-'
    brnz sign_change_INT_FLIP, $1
    slt $1, $0, 0
    brz sign_change_END, $1
sign_change_INT_FLIP:
    mul $0, $0, -1
    jump sign_change_END
sign_change_END:
    mov #0[1], $0
    return

read:
    mov $0, #0[0]
    seq $0, $0, 2
    brz read_INT, $0
    scanf $1
    jump read_END
read_INT:
    scani $1
read_END:
    mov #0[1], $1
    return

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
    return

writeln:
    param #0
    param #1
    call write, 2
    println
    return

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
    mov $1[1], 0.000000

    param $1
    call read, 1

    mema $2, 2
    mov $2[0], 3
    mov $2[1], &str_0

    param $2
    call write, 1

    param $0
    call writeln, 1

    mema $2, 2
    mov $2[0], 3
    mov $2[1], &str_1

    param $2
    call write, 1

    param $1
    call writeln, 1

    // assign a = b
    param $0 // lhs
    param $1 // rhs
    call set_var_val, 2

    mema $2, 2
    mov $2[0], 3
    mov $2[1], &str_2

    param $2
    call write, 1

    param $0
    call writeln, 1

    mema $2, 2
    mov $2[0], 3
    mov $2[1], &str_3

    param $2
    call write, 1

    param $1
    call writeln, 1

    return 0

func_add:
    // var int a
    mema $0, 2
    mov $0[1], 8.21
    mov *$0, 2

    // var int b
    mema $1, 2
    mov $1[1], 0.0
    mov *$1, 2

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

    and $5, $4, $5

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

    mema $0, 2
    mov $0[0], 2
    mov $0[1], -23.1

    param $0
    param '+'
    call sign_change, 2

    param $0
    param '-'
    call sign_change, 2

    param $0
    call writeln, 1

EOF:
    nop
