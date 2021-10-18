.table

char str_nil[] = "nil"
int list_nil[] = {3, 0}
char str_0[] = "insider other function a: "
char str_1[] = "global a: "
char str_2[] = "local a: "

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
main:

// var float a
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

jump func_main_END

func_main:
mema $2, 2
mov $2[0], 2
mov $2[1], 77.234700
push $2

pop $2
param $0
param $2
call set_var_val, 2

mema $2, 2
mov $2[0], 3
mov $2[1], &str_1
push $2

pop $2
param $2
call write, 1

push $0

pop $2
param $2
call writeln, 1

push $0
call func_writeglobal, 0

// var int a
mema $1, 2
mov $1[0], 1
mov $1[1], 0

mema $2, 2
mov $2[0], 1
mov $2[1], 2
push $2

pop $2
param $1
param $2
call set_var_val, 2

mema $2, 2
mov $2[0], 3
mov $2[1], &str_2
push $2

pop $2
param $2
call write, 1

push $1

pop $2
param $2
call writeln, 1

jump EOF

func_main_END:
jump func_main

EOF:
nop
