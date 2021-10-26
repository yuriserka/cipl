.table

char str_nil[] = "nil"
char str_0[] = "Digite os número de elementos da lista: "
char str_1[] = "Digite o elemento da lista: "
char str_2[] = " "
char str_3[] = "A nova lista tem "
char str_4[] = " elementos."
char str_5[] = "A nova lista não possui elementos."
char str_6[] = " "

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

// global var int list IL
mema $0, 3
mov $0[0], 4
mov $0[1], 0
mema $7, 0
mov $0[2], $7

// global var float list FL
mema $1, 3
mov $1[0], 5
mov $1[1], 0
mema $7, 0
mov $1[2], $7

jump func_read_list_END

func_read_list:
pop $1
pop $0
// param int n
mema $5, 2
mov $5[0], 1
mov $6, #0[1]
mov $5[1], $6

// local var int i
mema $2, 2
mov $2[0], 1
mov $2[1], 0

mema $6, 2
mov $6[0], 2
mov $6[1], 435.700000
push $6

pop $6

param $6
param '-'
call sign_change, 2

push $6

pop $6
param $6
param 1
call cast, 2
pop $6
push $6

pop $6
param $2
param $6
call set_var_val, 2

// local var int list new
mema $3, 3
mov $3[0], 4
mov $3[1], 0
mema $7, 0
mov $3[2], $7

mema $6, 3
mov $6[0], 3
mov $6[1], 0
mema $7, 0
mov $6[2], $7
push $6

pop $6
param $3
param $6
call set_var_val, 2

mema $6, 2
mov $6[0], 1
mov $6[1], 0
push $6

pop $6
param $2
param $6
call set_var_val, 2

read_list_L0_LOOP:
push $2

push $5

pop $7

pop $6

param $6
call get_var_val, 1
pop $8

param $7
call get_var_val, 1
pop $9

slt $9, $8, $9

param $9
call set_bool, 1
pop $9

mema $8, 2
mov $8[0], 1
mov $8[1], $9
push $8

pop $6

param $6
call get_var_val, 1
pop $7

seq $7, $7, 0
param $7
call set_bool, 1
pop $7

brnz read_list_L0_END, $7
// local var int elem
mema $4, 2
mov $4[0], 1
mov $4[1], 0

mema $6, 2
mov $6[0], 3
mov $6[1], &str_1
push $6

pop $6
param $6
call writeln, 1

push $4

pop $6
param $6
call read, 1

push $4

push $3

pop $6

pop $7

param $6
param $7
call list_insert, 2
pop $8
push $8

pop $6
param $3
param $6
call set_var_val, 2

push $2

mema $6, 2
mov $6[0], 1
mov $6[1], 1
push $6

pop $7

pop $6

param $6
call get_var_val, 1
pop $8

param $7
call get_var_val, 1
pop $9

add $9, $8, $9

mema $8, 2
mov $8[0], 1
mov $8[1], $9
push $8

pop $6
param $2
param $6
call set_var_val, 2

jump read_list_L0_LOOP
read_list_L0_END:
push $3

pop $6
return $6

func_read_list_END:

jump func_succ_END

func_succ:
pop $1
pop $0
// param int i
mema $2, 2
mov $2[0], 1
mov $3, #0[1]
mov $2[1], $3

push $2

mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3

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
param 2
call cast, 2
pop $3
push $3

pop $3
return $3

func_succ_END:

jump func_leq_10_END

func_leq_10:
pop $1
pop $0
// param float x
mema $2, 2
mov $2[0], 2
mov $3, #0[1]
mov $2[1], $3

push $2

mema $3, 2
mov $3[0], 1
mov $3[1], 10
push $3

pop $3
param $3
param 2
call cast, 2
pop $3
push $3

pop $4

pop $3

param $3
call get_var_val, 1
pop $5

param $4
call get_var_val, 1
pop $6

sleq $6, $5, $6

param $6
call set_bool, 1
pop $6

mema $5, 2
mov $5[0], 1
mov $5[1], $6
push $5

pop $3
return $3

func_leq_10_END:

jump func_main_END

func_main:
mema $6, 2
mov $6[0], 3
mov $6[1], &str_0
push $6

pop $6
param $6
call writeln, 1

// local var int n
mema $2, 2
mov $2[0], 1
mov $2[1], 0

// local var float list FL10
mema $3, 3
mov $3[0], 5
mov $3[1], 0
mema $7, 0
mov $3[2], $7

push $2

pop $6
param $6
call read, 1

push $2

pop $6
param $6
push $0
push $1
call func_read_list, 3

pop $6
param $0
param $6
call set_var_val, 2

push $0

pop $6
mema $8, 3
mov $8[0], 5
mov $9, $6[1]
mema $7, $9
func_main_list_for_each_L0_FOR:
mov $9, 0
mov $11, 0
func_main_list_for_each_L0_LOOP:
mov $10, $6[1]
slt $10, $9, $10
brz func_main_list_for_each_L0_END, $10
param $6
param $9
call list_peek, 2
pop $10
push $10
pop $10
param $10
push $0
push $1
call func_succ, 3
func_main_list_for_each_L0_ADD:
pop $10
mov $7[$11], $10
add $11, $11, 1
func_main_list_for_each_L0_CONTINUE:
add $9, $9, 1
jump func_main_list_for_each_L0_LOOP
func_main_list_for_each_L0_END:
brnz func_main_list_for_each_L0_NOT_NIL, $11
mema $7, 0
func_main_list_for_each_L0_NOT_NIL:
mov $8[1], $11
mov $8[2], $7
push $8

pop $6
param $1
param $6
call set_var_val, 2

push $1

pop $6
mema $8, 3
mov $8[0], 5
mov $9, $6[1]
mema $7, $9
func_main_list_for_each_L1_FOR:
mov $9, 0
mov $11, 0
func_main_list_for_each_L1_LOOP:
mov $10, $6[1]
slt $10, $9, $10
brz func_main_list_for_each_L1_END, $10
param $6
param $9
call list_peek, 2
pop $10
push $10
pop $10
param $10
push $0
push $1
call func_leq_10, 3
pop $12
param $12
call get_var_val, 1
pop $12
param $12
call set_bool, 1
pop $12
brz func_main_list_for_each_L1_CONTINUE, $12
push $10
func_main_list_for_each_L1_ADD:
pop $10
mov $7[$11], $10
add $11, $11, 1
func_main_list_for_each_L1_CONTINUE:
add $9, $9, 1
jump func_main_list_for_each_L1_LOOP
func_main_list_for_each_L1_END:
brnz func_main_list_for_each_L1_NOT_NIL, $11
mema $7, 0
func_main_list_for_each_L1_NOT_NIL:
mov $8[1], $11
mov $8[2], $7
push $8

pop $6
param $3
param $6
call set_var_val, 2

push $3

mema $6, 3
mov $6[0], 3
mov $6[1], 0
mema $7, 0
mov $6[2], $7
push $6

pop $7

pop $6

param $6
call get_var_val, 1
pop $8

param $7
call get_var_val, 1
pop $9

seq $9, $8, $9
not $9, $9
param $9
call set_bool, 1
pop $9

mema $8, 2
mov $8[0], 1
mov $8[1], $9
push $8

pop $6

param $6
call get_var_val, 1
pop $7

seq $7, $7, 0
param $7
call set_bool, 1
pop $7

brnz main_L2_ELSE, $7
// local var float list AUXL
mema $4, 3
mov $4[0], 5
mov $4[1], 0
mema $7, 0
mov $4[2], $7

// local var int n
mema $5, 2
mov $5[0], 1
mov $5[1], 0

mema $6, 2
mov $6[0], 1
mov $6[1], 0
push $6

pop $6
param $5
param $6
call set_var_val, 2

push $3

pop $6
param $4
param $6
call set_var_val, 2

main_L3_LOOP:
push $4

mema $6, 3
mov $6[0], 3
mov $6[1], 0
mema $7, 0
mov $6[2], $7
push $6

pop $7

pop $6

param $6
call get_var_val, 1
pop $8

param $7
call get_var_val, 1
pop $9

seq $9, $8, $9
not $9, $9
param $9
call set_bool, 1
pop $9

mema $8, 2
mov $8[0], 1
mov $8[1], $9
push $8

pop $6

param $6
call get_var_val, 1
pop $7

seq $7, $7, 0
param $7
call set_bool, 1
pop $7

brnz main_L3_END, $7
push $5

mema $6, 2
mov $6[0], 1
mov $6[1], 1
push $6

pop $7

pop $6

param $6
call get_var_val, 1
pop $8

param $7
call get_var_val, 1
pop $9

add $9, $8, $9

mema $8, 2
mov $8[0], 1
mov $8[1], $9
push $8

pop $6
param $5
param $6
call set_var_val, 2

push $4

pop $6

param $6
call list_head, 1
pop $6
push $6

pop $6
param $6
call write, 1

mema $6, 2
mov $6[0], 3
mov $6[1], &str_6
push $6

pop $6
param $6
call write, 1

push $4

pop $6

param $6
call list_tail, 1
pop $6
push $6

pop $6
param $4
param $6
call set_var_val, 2

jump main_L3_LOOP
main_L3_END:
mema $6, 2
mov $6[0], 3
mov $6[1], &str_2
push $6

pop $6
param $6
call writeln, 1

mema $6, 2
mov $6[0], 3
mov $6[1], &str_3
push $6

pop $6
param $6
call write, 1

push $5

pop $6
param $6
call write, 1

mema $6, 2
mov $6[0], 3
mov $6[1], &str_4
push $6

pop $6
param $6
call writeln, 1

jump main_L2_END
main_L2_ELSE:
mema $6, 2
mov $6[0], 3
mov $6[1], &str_5
push $6

pop $6
param $6
call writeln, 1

main_L2_END:
mema $6, 2
mov $6[0], 1
mov $6[1], 0
push $6

pop $6
jump EOF

func_main_END:

jump func_main

EOF:
nop
