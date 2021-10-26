.table

char str_nil[] = "nil"
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

// global var int x
mema $0, 2
mov $0[0], 1
mov $0[1], 0

// global var float y
mema $1, 2
mov $1[0], 2
mov $1[1], 0.000000

// global var int list il
mema $2, 3
mov $2[0], 4
mov $2[1], 0
mema $6, 0
mov $2[2], $6

// global var float list fl
mema $3, 3
mov $3[0], 5
mov $3[1], 0
mema $6, 0
mov $3[2], $6

jump func_f_END

func_f:
pop $3
pop $2
pop $1
pop $0
// param int a
mema $8, 2
mov $8[0], 1
mov $9, #0[1]
mov $8[1], $9

// param float b
mema $9, 2
mov $9[0], 2
mov $10, #1[1]
mov $9[1], $10

// param int c
mema $10, 2
mov $10[0], 1
mov $11, #2[1]
mov $10[1], $11

// local var int h
mema $4, 2
mov $4[0], 1
mov $4[1], 0

// local var float j
mema $5, 2
mov $5[0], 2
mov $5[1], 0.000000

// local var int list k
mema $6, 3
mov $6[0], 4
mov $6[1], 0
mema $12, 0
mov $6[2], $12

// local var float list l
mema $7, 3
mov $7[0], 5
mov $7[1], 0
mema $12, 0
mov $7[2], $12

push $8

mema $11, 2
mov $11[0], 1
mov $11[1], 1
push $11

pop $12

pop $11

param $11
call get_var_val, 1
pop $13

param $12
call get_var_val, 1
pop $14

add $14, $13, $14

mema $13, 2
mov $13[0], 1
mov $13[1], $14
push $13

pop $11
param $0
param $11
call set_var_val, 2

push $9

mema $11, 2
mov $11[0], 2
mov $11[1], 3.400000
push $11

pop $12

pop $11

param $11
call get_var_val, 1
pop $13

param $12
call get_var_val, 1
pop $14

add $14, $13, $14

mema $13, 2
mov $13[0], 2
mov $13[1], $14
push $13

pop $11
param $1
param $11
call set_var_val, 2

mema $11, 2
mov $11[0], 1
mov $11[1], 1
push $11

mema $11, 2
mov $11[0], 1
mov $11[1], 2
push $11

mema $11, 2
mov $11[0], 1
mov $11[1], 3
push $11

push #3

pop $11

pop $12

param $11
param $12
call list_insert, 2
pop $13
push $13

pop $11

pop $12

param $11
param $12
call list_insert, 2
pop $13
push $13

pop $11

pop $12

param $11
param $12
call list_insert, 2
pop $13
push $13

pop $11
param #3
param $11
call set_var_val, 2

push #3

pop $11
param $2
param $11
call set_var_val, 2

push $4

pop $11
return $11

func_f_END:

jump func_main_END

func_main:
mema $5, 2
mov $5[0], 1
mov $5[1], 213
push $5

pop $5
param $0
param $5
call set_var_val, 2

mema $5, 2
mov $5[0], 1
mov $5[1], 1
push $5

pop $5
param $5
mema $5, 2
mov $5[0], 1
mov $5[1], 2
push $5

pop $6
param $6
param 2
call cast, 2
pop $6
push $6

pop $6
param $6
mema $5, 2
mov $5[0], 2
mov $5[1], 4.650000
push $5

pop $7
param $7
param 1
call cast, 2
pop $7
push $7

pop $7
param $7
mema $5, 3
mov $5[0], 3
mov $5[1], 0
mema $6, 0
mov $5[2], $6
push $5

pop $8
param $8
mema $5, 2
mov $5[0], 1
mov $5[1], 1
push $5

pop $5
param $5
param 2
call cast, 2
pop $5
push $5

mema $5, 2
mov $5[0], 2
mov $5[1], 4.600000
push $5

mema $5, 3
mov $5[0], 3
mov $5[1], 0
mema $6, 0
mov $5[2], $6
push $5

pop $5

pop $6

param $5
param $6
call list_insert, 2
pop $7
push $7

pop $5

pop $6

param $5
param $6
call list_insert, 2
pop $7
push $7

pop $9
param $9
push $0
push $1
push $2
push $3
call func_f, 9

push $0

pop $5
param $5
param 2
call cast, 2
pop $5
push $5

push $1

pop $6

pop $5

param $5
call get_var_val, 1
pop $7

param $6
call get_var_val, 1
pop $8

add $8, $7, $8

mema $7, 2
mov $7[0], 2
mov $7[1], $8
push $7

pop $5
param $5
call writeln, 1

// local var int list it
mema $4, 3
mov $4[0], 4
mov $4[1], 0
mema $6, 0
mov $4[2], $6

push $2

pop $5
param $4
param $5
call set_var_val, 2

main_L0_LOOP:
push $4

mema $5, 3
mov $5[0], 3
mov $5[1], 0
mema $6, 0
mov $5[2], $6
push $5

pop $6

pop $5

param $5
call get_var_val, 1
pop $7

param $6
call get_var_val, 1
pop $8

seq $8, $7, $8
not $8, $8
param $8
call set_bool, 1
pop $8

mema $7, 2
mov $7[0], 1
mov $7[1], $8
push $7

pop $5

param $5
call get_var_val, 1
pop $6

seq $6, $6, 0
param $6
call set_bool, 1
pop $6

brnz main_L0_END, $6
push $4

pop $5

param $5
call list_head, 1
pop $5
push $5

pop $5
param $5
call writeln, 1

push $4

pop $5

param $5
call list_tail, 1
pop $5
push $5

pop $5
param $4
param $5
call set_var_val, 2

jump main_L0_LOOP
main_L0_END:
jump EOF

func_main_END:

jump func_main

EOF:
nop
