.table

char str_nil[] = "nil"
char str_0[] = "digite o valor de \033[33m'a'\033[0m: "
char str_1[] = "func call: 'calc(a)' = "
char str_2[] = "static int: "
char str_3[] = "static float: "
char str_4[] = "static '"
char str_5[] = " + 1 + 65 - 7.89 * 5.2 / 0.45' = "

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
seq $0, #2, 0
brz set_var_val_FROM_VAR, $0
mov $0, *#0
mov $3, #1
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

func_arith:
// param float a
mema $0, 2
mov $0[0], 2
mov $1, #0[1]
mov $0[1], $1

push $0

mema $1, 2
mov $1[0], 1
mov $1[1], 2
push $1

pop $1
param $1
param 2
call cast, 2
pop $1
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

add $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

mema $1, 2
mov $1[0], 1
mov $1[1], 3
push $1

mema $1, 2
mov $1[0], 1
mov $1[1], 4
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

mul $4, $3, $4

mema $3, 2
mov $3[0], 1
mov $3[1], $4
push $3

mema $1, 2
mov $1[0], 1
mov $1[1], 5
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

div $4, $3, $4

mema $3, 2
mov $3[0], 1
mov $3[1], $4
push $3

pop $1
param $1
param 2
call cast, 2
pop $1
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

sub $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

mema $1, 2
mov $1[0], 2
mov $1[1], 1.100000
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

add $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

mema $1, 2
mov $1[0], 2
mov $1[1], 2.100000
push $1

mema $1, 2
mov $1[0], 1
mov $1[1], 10
push $1

pop $1
param $1
param 2
call cast, 2
pop $1
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

mul $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

sub $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

pop $1
return $1

main:
// var int a
mema $0, 2
mov $0[0], 1
mov $0[1], 0
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
call read, 1

mema $1, 2
mov $1[0], 3
mov $1[1], &str_1
push $1

pop $1
param $1
call write, 1

push $0

pop $1
param $1
param 2
call cast, 2
pop $1
push $1

pop $1
param $1
call func_arith, 1

pop $1
param $1
call writeln, 1

mema $1, 2
mov $1[0], 3
mov $1[1], &str_2
push $1

pop $1
param $1
call write, 1

mema $1, 2
mov $1[0], 1
mov $1[1], 78
push $1

pop $1
param $1
call writeln, 1

mema $1, 2
mov $1[0], 3
mov $1[1], &str_3
push $1

pop $1
param $1
call write, 1

mema $1, 2
mov $1[0], 2
mov $1[1], 3.141590
push $1

pop $1
param $1
call writeln, 1

mema $1, 2
mov $1[0], 3
mov $1[1], &str_4
push $1

pop $1
param $1
call write, 1

push $0

pop $1
param $1
call write, 1

mema $1, 2
mov $1[0], 3
mov $1[1], &str_5
push $1

pop $1
param $1
call write, 1

push $0

mema $1, 2
mov $1[0], 1
mov $1[1], 1
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

add $4, $3, $4

mema $3, 2
mov $3[0], 1
mov $3[1], $4
push $3

mema $1, 2
mov $1[0], 1
mov $1[1], 65
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

add $4, $3, $4

mema $3, 2
mov $3[0], 1
mov $3[1], $4
push $3

pop $1
param $1
param 2
call cast, 2
pop $1
push $1

mema $1, 2
mov $1[0], 2
mov $1[1], 7.890000
push $1

mema $1, 2
mov $1[0], 2
mov $1[1], 5.200000
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

mul $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

mema $1, 2
mov $1[0], 2
mov $1[1], 0.450000
push $1

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

div $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

pop $2

pop $1

param $1
call get_var_val, 1
pop $3

param $2
call get_var_val, 1
pop $4

sub $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

pop $1
param $1
call writeln, 1

jump EOF

EOF:
nop
