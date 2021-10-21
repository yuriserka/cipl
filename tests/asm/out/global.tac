.table

char str_nil[] = "nil"
int list_nil[] = {3, 0}
char str_0[] = "insider other function a: "
char str_1[] = "enter value for the meta-parameter B: "
char str_2[] = "global a: "
char str_3[] = "local a=(2) + global b: "

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

main:

// global var float a
mema $0, 2
mov $0[0], 2
mov $0[1], 0.000000

jump func_writeglobal_END

func_writeglobal:
pop $0
mema $1, 2
mov $1[0], 3
mov $1[1], &str_0
push $1

pop $1
param $1
call write, 1

push $0

pop $1
param $1
call writeln, 1

mema $1, 2
mov $1[0], 1
mov $1[1], 0
push $1

pop $1
return $1

func_writeglobal_END:

// global var int b
mema $1, 2
mov $1[0], 1
mov $1[1], 0

jump func_readb_END

func_readb:
pop $1
pop $0
mema $2, 2
mov $2[0], 3
mov $2[1], &str_1
push $2

pop $2
param $2
call write, 1

push $1

pop $2
param $2
call read, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
return $2

func_readb_END:

jump func_main_END

func_main:
mema $3, 2
mov $3[0], 2
mov $3[1], 77.234700
push $3

pop $3
param $0
param $3
call set_var_val, 2

mema $3, 2
mov $3[0], 3
mov $3[1], &str_2
push $3

pop $3
param $3
call write, 1

push $0

pop $3
param $3
call writeln, 1

push $0
push $1
call func_readb, 0

push $0
call func_writeglobal, 0

// local var int a
mema $2, 2
mov $2[0], 1
mov $2[1], 0

mema $3, 2
mov $3[0], 1
mov $3[1], 2
push $3

pop $3
param $2
param $3
call set_var_val, 2

mema $3, 2
mov $3[0], 3
mov $3[1], &str_3
push $3

pop $3
param $3
call write, 1

push $2

push $1

pop $4

pop $3

param $3
call get_var_val, 1
pop $5

param $4
call get_var_val, 1
pop $6

add $6, $5, $6

mema $5, 2
mov $5[0], 1
mov $5[1], $6
push $5

pop $3
param $3
call writeln, 1

mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3

pop $3
jump EOF

func_main_END:

jump func_main

EOF:
nop
