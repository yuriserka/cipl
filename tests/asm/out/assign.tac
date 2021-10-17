.table

char str_nil[] = "nil"
char str_0[] = "digite o valor de \033[33m'a'\033[0m na func: "
char str_1[] = "func a: "
char str_2[] = "func b: "
char str_3[] = "digite o valor de \033[33m'a'\033[0m na main: "
char str_4[] = "b4 a: "
char str_5[] = "after a: "
char str_6[] = "b: "
char str_7[] = "c: "
char str_8[] = "d = c: "

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

func_readme:
// param int a
mema $1, 2
mov $1[0], 1
mov $2, #0[1]
mov $1[1], $2

// param float c
mema $2, 2
mov $2[0], 2
mov $3, #1[1]
mov $2[1], $3

mema $3, 2
mov $3[0], 3
mov $3[1], &str_0
push $3

pop $3
param $3
call write, 1

push $1

pop $3
param $3
call read, 1

// var int b
mema $0, 2
mov $0[0], 1
mov $0[1], 0

push $1

pop $3
param $3
param 2
call cast, 2
pop $3
push $3

mema $3, 2
mov $3[0], 1
mov $3[1], 7
push $3

pop $3
param $3
param 2
call cast, 2
pop $3
push $3

push $2

pop $4

pop $3

param $3
call get_var_val, 1
pop $5

param $4
call get_var_val, 1
pop $6

div $6, $5, $6

mema $5, 2
mov $5[0], 2
mov $5[1], $6
push $5

mema $3, 2
mov $3[0], 2
mov $3[1], 2.500000
push $3

pop $4

pop $3

param $3
call get_var_val, 1
pop $5

param $4
call get_var_val, 1
pop $6

mul $6, $5, $6

mema $5, 2
mov $5[0], 2
mov $5[1], $6
push $5

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
mov $5[0], 2
mov $5[1], $6
push $5

pop $3
param $3
param 1
call cast, 2
pop $3
push $3

pop $3
param $0
param $3
call set_var_val, 2

mema $3, 2
mov $3[0], 3
mov $3[1], &str_1
push $3

pop $3
param $3
call write, 1

push $1

pop $3
param $3
call writeln, 1

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

pop $3
return $3

main:
// var int a
mema $0, 2
mov $0[0], 1
mov $0[1], 0

mema $4, 2
mov $4[0], 3
mov $4[1], &str_3
push $4

pop $4
param $4
call write, 1

push $0

pop $4
param $4
call read, 1

mema $4, 2
mov $4[0], 3
mov $4[1], &str_4
push $4

pop $4
param $4
call write, 1

push $0

pop $4
param $4
call writeln, 1

// var int b
mema $1, 2
mov $1[0], 1
mov $1[1], 0

push $0

pop $4
param $4
mema $4, 2
mov $4[0], 2
mov $4[1], 1.570000
push $4

pop $5
param $5
call func_readme, 2

pop $4
param $1
param $4
call set_var_val, 2

mema $4, 2
mov $4[0], 3
mov $4[1], &str_5
push $4

pop $4
param $4
call write, 1

push $0

pop $4
param $4
call writeln, 1

mema $4, 2
mov $4[0], 3
mov $4[1], &str_6
push $4

pop $4
param $4
call write, 1

push $1

pop $4
param $4
call writeln, 1

// var float c
mema $2, 2
mov $2[0], 2
mov $2[1], 0.000000

mema $4, 2
mov $4[0], 2
mov $4[1], 1.500000
push $4

push $1

push $0

pop $5

pop $4

param $4
call get_var_val, 1
pop $6

param $5
call get_var_val, 1
pop $7

mul $7, $6, $7

mema $6, 2
mov $6[0], 1
mov $6[1], $7
push $6

pop $4
param $4
param 2
call cast, 2
pop $4
push $4

pop $5

pop $4

param $4
call get_var_val, 1
pop $6

param $5
call get_var_val, 1
pop $7

sub $7, $6, $7

mema $6, 2
mov $6[0], 2
mov $6[1], $7
push $6

pop $4
param $2
param $4
call set_var_val, 2

mema $4, 2
mov $4[0], 3
mov $4[1], &str_7
push $4

pop $4
param $4
call write, 1

push $2

pop $4
param $4
call writeln, 1

// var float d
mema $3, 2
mov $3[0], 2
mov $3[1], 0.000000

push $2

pop $4
param $3
param $4
call set_var_val, 2

mema $4, 2
mov $4[0], 3
mov $4[1], &str_8
push $4

pop $4
param $4
call write, 1

push $3

pop $4
param $4
call writeln, 1

jump EOF

EOF:
nop