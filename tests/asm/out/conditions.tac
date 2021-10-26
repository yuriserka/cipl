.table

char str_nil[] = "nil"
char str_0[] = "digite o valor de \033[33m'a'\033[0m: "
char str_1[] = "it works!"
char str_2[] = "suspicious"
char str_3[] = "no else"
char str_4[] = "teenage"
char str_5[] = "only when a = "
char str_6[] = "nested ifs"
char str_7[] = "a = "

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
mov $0, #1[2]
mov #0[2], $0
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
jump sign_change_END
sign_change_FLOAT_FLIP:
mul $0, $0, -1.0
jump sign_change_END
sign_change_INT:
seq $1, #1, '-'
brnz sign_change_INT_FLIP, $1
jump sign_change_END
sign_change_INT_FLIP:
mul $0, $0, -1
jump sign_change_END
sign_change_END:
mov #0[1], $0
return

set_bool:
brnz set_bool_TRUE, #0
mov $0, 0
jump set_bool_END
set_bool_TRUE:
mov $0, 1
set_bool_END:
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

list_peek:
mov $0, #0[2]
mov $0, $0[#1]
return $0

list_insert:
mema $0, 3
mov $1, #0[0]
mov $0[0], $1
mov $1, #0[1]
add $1, $1, 1
mov $0[1], $1
mov $2, $1
mema $1, $2
mema $2, 2
mov $3, #1[0]
mov $2[0], $3
mov $3, #1[1]
mov $2[1], $3
mov $1[0], $2
list_insert_FOR:
mov $2, 0
list_insert_LOOP:
mov $3, #0[1]
slt $3, $2, $3
brz list_insert_END, $3 
param #0
param $2
call list_peek, 2
pop $3
add $4, $2, 1
mov $1[$4], $3
add $2, $2, 1
jump list_insert_LOOP
list_insert_END:
mov $0[2], $1
return $0

list_head:
param #0
param 0
call list_peek, 2
pop $0
return $0

list_tail:
mema $0, 3
mov $1, #0[0]
mov $0[0], $1
mov $1, #0[1]
sub $1, $1, 1
mov $0[1], $1
mov $2, $1
mema $1, $2
list_tail_FOR:
mov $2, 1
list_tail_LOOP:
mov $3, #0[1]
slt $3, $2, $3
brz list_tail_END, $3 
param #0
param $2
call list_peek, 2
pop $3
sub $4, $2, 1
mov $1[$4], $3
add $2, $2, 1
jump list_tail_LOOP
list_tail_END:
mov $0[2], $1
return $0

list_pop_tail:
param #0
call list_tail, 1
pop $0
mov $1, $0[1]
mov #0[1], $1
mov $1, $0[2]
mov #0[2], $1
return #0

main:

// global var int a
mema $0, 2
mov $0[0], 1
mov $0[1], 0

jump func_main_END

func_main:
mema $2, 2
mov $2[0], 3
mov $2[1], &str_0
push $2

pop $2
param $2
call write, 1

push $0

pop $2
param $2
call read, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

sleq $6, $5, $4
seq $7, $5, $4
not $7, $7
and $5, $6, $7

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

mema $2, 2
mov $2[0], 1
mov $2[1], 123
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $2

param $2
call get_var_val, 1
pop $3

seq $3, $3, 0
param $3
call set_bool, 1
pop $3

brnz main_L0_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_1
push $2

pop $2
param $2
call writeln, 1

// local var int a
mema $1, 2
mov $1[0], 1
mov $1[1], 0

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 2
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

add $5, $4, $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

mema $2, 2
mov $2[0], 1
mov $2[1], 3
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

mul $5, $4, $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

mema $2, 2
mov $2[0], 1
mov $2[1], 5
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

div $5, $4, $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

sub $5, $4, $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 2
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

slt $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

mema $2, 2
mov $2[0], 1
mov $2[1], 3
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 4
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

slt $6, $4, $5
not $5, $6

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

sleq $6, $5, $4
seq $7, $5, $4
not $7, $7
and $5, $6, $7

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $2
param $1
param $2
call set_var_val, 2

push $1

pop $2

param $2
call get_var_val, 1
pop $3

seq $3, $3, 0
param $3
call set_bool, 1
pop $3

brnz main_L1_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_6
push $2

pop $2
param $2
call writeln, 1

mema $2, 2
mov $2[0], 3
mov $2[1], &str_7
push $2

pop $2
param $2
call write, 1

push $1

pop $2
param $2
call writeln, 1

jump main_L1_END
main_L1_ELSE:
main_L1_END:
jump main_L0_END
main_L0_ELSE:
mema $2, 2
mov $2[0], 3
mov $2[1], &str_2
push $2

pop $2
param $2
call writeln, 1

main_L0_END:
push $0

mema $2, 2
mov $2[0], 1
mov $2[1], 10
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

slt $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $2

param $2
call get_var_val, 1
pop $3

seq $3, $3, 0
param $3
call set_bool, 1
pop $3

brnz main_L2_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_3
push $2

pop $2
param $2
call writeln, 1

jump main_L2_END
main_L2_ELSE:
push $0

mema $2, 2
mov $2[0], 1
mov $2[1], 10
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

slt $6, $4, $5
not $5, $6

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

push $0

mema $2, 2
mov $2[0], 1
mov $2[1], 20
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

slt $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $2

param $2
call get_var_val, 1
pop $3

seq $3, $3, 0
param $3
call set_bool, 1
pop $3

brnz main_L3_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_4
push $2

pop $2
param $2
call writeln, 1

jump main_L3_END
main_L3_ELSE:
mema $2, 2
mov $2[0], 1
mov $2[1], 100
push $2

pop $2
param $0
param $2
call set_var_val, 2

main_L3_END:
main_L2_END:
push $0

pop $2

param $2
call get_var_val, 1
pop $2

not $2, $2
mema $3, 2
mov $3[0], 1
mov $3[1], $2
push $3

pop $2

param $2
call get_var_val, 1
pop $3

seq $3, $3, 0
param $3
call set_bool, 1
pop $3

brnz main_L4_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_5
push $2

pop $2
param $2
call write, 1

push $0

pop $2
param $2
call writeln, 1

jump main_L4_END
main_L4_ELSE:
main_L4_END:
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
jump EOF

func_main_END:

jump func_main

EOF:
nop
