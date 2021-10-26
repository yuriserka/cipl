.table

char str_nil[] = "nil"
char str_0[] = "["
char str_1[] = "]"
char str_2[] = ", "

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

jump func_printf_END

func_printf:
push #0

mema $0, 3
mov $0[0], 3
mov $0[1], 0
mema $1, 0
mov $0[2], $1
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

seq $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0

param $0
call get_var_val, 1
pop $1

seq $1, $1, 0
param $1
call set_bool, 1
pop $1

brnz printf_L0_ELSE, $1
mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0
jump printf_L0_END
printf_L0_ELSE:
printf_L0_END:
push #0

pop $0

param $0
call list_head, 1
pop $0
push $0

pop $0
param $0
call write, 1

push #0

pop $0

param $0
call list_tail, 1
pop $0
push $0

mema $0, 3
mov $0[0], 3
mov $0[1], 0
mema $1, 0
mov $0[2], $1
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

seq $3, $2, $3
not $3, $3
param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0

param $0
call get_var_val, 1
pop $1

seq $1, $1, 0
param $1
call set_bool, 1
pop $1

brnz printf_L1_ELSE, $1
mema $0, 2
mov $0[0], 3
mov $0[1], &str_2
push $0

pop $0
param $0
call write, 1

jump printf_L1_END
printf_L1_ELSE:
printf_L1_END:
push #0

pop $0

param $0
call list_tail, 1
pop $0
push $0

pop $0
param $0
call func_printf, 1

pop $0
return $0

func_printf_END:

jump func_size_END

func_size:
push #0

mema $0, 3
mov $0[0], 3
mov $0[1], 0
mema $1, 0
mov $0[2], $1
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

seq $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0

param $0
call get_var_val, 1
pop $1

seq $1, $1, 0
param $1
call set_bool, 1
pop $1

brnz size_L0_ELSE, $1
mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0
jump size_L0_END
size_L0_ELSE:
size_L0_END:
push #0

pop $0

param $0
call list_tail, 1
pop $0
push $0

pop $0
param $0
call func_size, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

add $3, $2, $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
return $0

func_size_END:

jump func_peek_END

func_peek:
// param int pos
mema $2, 2
mov $2[0], 1
mov $3, #1[1]
mov $2[1], $3

// local var int i
mema $0, 2
mov $0[0], 1
mov $0[1], 0

// local var int list it
mema $1, 3
mov $1[0], 4
mov $1[1], 0
mema $4, 0
mov $1[2], $4

push #0

pop $3
param $1
param $3
call set_var_val, 2

mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3

pop $3
param $0
param $3
call set_var_val, 2

peek_L0_LOOP:
push $0

push $2

pop $4

pop $3

param $3
call get_var_val, 1
pop $5

param $4
call get_var_val, 1
pop $6

slt $6, $5, $6

param $6
call set_bool, 1
pop $6

mema $5, 2
mov $5[0], 1
mov $5[1], $6
push $5

pop $3

param $3
call get_var_val, 1
pop $4

seq $4, $4, 0
param $4
call set_bool, 1
pop $4

brnz peek_L0_END, $4
push $1

pop $3

param $3
call list_tail, 1
pop $3
push $3

pop $3
param $1
param $3
call set_var_val, 2

push $0

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
param $0
param $3
call set_var_val, 2

jump peek_L0_LOOP
peek_L0_END:
push $1

pop $3

param $3
call list_head, 1
pop $3
push $3

pop $3
return $3

func_peek_END:

jump func_twoSum_END

func_twoSum:
// param int target
mema $4, 2
mov $4[0], 1
mov $5, #1[1]
mov $4[1], $5

// local var int i
mema $0, 2
mov $0[0], 1
mov $0[1], 0

// local var int j
mema $1, 2
mov $1[0], 1
mov $1[1], 0

mema $5, 2
mov $5[0], 1
mov $5[1], 0
push $5

pop $5
param $0
param $5
call set_var_val, 2

twoSum_L0_LOOP:
push $0

push #0

pop $5
param $5
call func_size, 1

pop $6

pop $5

param $5
call get_var_val, 1
pop $7

param $6
call get_var_val, 1
pop $8

slt $8, $7, $8

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

brnz twoSum_L0_END, $6
mema $5, 2
mov $5[0], 1
mov $5[1], 0
push $5

pop $5
param $1
param $5
call set_var_val, 2

twoSum_L1_LOOP:
push $1

push #0

pop $5
param $5
call func_size, 1

pop $6

pop $5

param $5
call get_var_val, 1
pop $7

param $6
call get_var_val, 1
pop $8

slt $8, $7, $8

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

brnz twoSum_L1_END, $6
// local var int l
mema $2, 2
mov $2[0], 1
mov $2[1], 0

push #0

pop $5
param $5
push $0

pop $6
param $6
call func_peek, 2

pop $5
param $2
param $5
call set_var_val, 2

// local var int r
mema $3, 2
mov $3[0], 1
mov $3[1], 0

push #0

pop $5
param $5
push $1

pop $6
param $6
call func_peek, 2

pop $5
param $3
param $5
call set_var_val, 2

push $0

push $1

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

push $2

push $3

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
mov $7[0], 1
mov $7[1], $8
push $7

push $4

pop $6

pop $5

param $5
call get_var_val, 1
pop $7

param $6
call get_var_val, 1
pop $8

seq $8, $7, $8

param $8
call set_bool, 1
pop $8

mema $7, 2
mov $7[0], 1
mov $7[1], $8
push $7

pop $6

pop $5

param $5
call get_var_val, 1
pop $7

param $6
call get_var_val, 1
pop $8

and $8, $7, $8

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

brnz twoSum_L2_ELSE, $6
push $0

push $1

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

pop $5
return $5
jump twoSum_L2_END
twoSum_L2_ELSE:
twoSum_L2_END:
push $1

mema $5, 2
mov $5[0], 1
mov $5[1], 1
push $5

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
mov $7[0], 1
mov $7[1], $8
push $7

pop $5
param $1
param $5
call set_var_val, 2

jump twoSum_L1_LOOP
twoSum_L1_END:
push $0

mema $5, 2
mov $5[0], 1
mov $5[1], 1
push $5

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
mov $7[0], 1
mov $7[1], $8
push $7

pop $5
param $0
param $5
call set_var_val, 2

jump twoSum_L0_LOOP
twoSum_L0_END:

func_twoSum_END:

jump func_print_ans_END

func_print_ans:
mema $0, 2
mov $0[0], 3
mov $0[1], &str_0
push $0

pop $0
param $0
call write, 1

push #0

pop $0
param $0
call func_printf, 1

mema $0, 2
mov $0[0], 3
mov $0[1], &str_1
push $0

pop $0
param $0
call writeln, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
return $0

func_print_ans_END:

jump func_run_tests_END

func_run_tests:
mema $0, 2
mov $0[0], 1
mov $0[1], 2
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 7
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 11
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 15
push $0

mema $0, 3
mov $0[0], 3
mov $0[1], 0
mema $1, 0
mov $0[2], $1
push $0

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0
param $0
mema $0, 2
mov $0[0], 1
mov $0[1], 9
push $0

pop $1
param $1
call func_twoSum, 2

pop $0
param $0
call func_print_ans, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 3
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 2
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 4
push $0

mema $0, 3
mov $0[0], 3
mov $0[1], 0
mema $1, 0
mov $0[2], $1
push $0

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0
param $0
mema $0, 2
mov $0[0], 1
mov $0[1], 6
push $0

pop $1
param $1
call func_twoSum, 2

pop $0
param $0
call func_print_ans, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 3
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 3
push $0

mema $0, 3
mov $0[0], 3
mov $0[1], 0
mema $1, 0
mov $0[2], $1
push $0

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0

pop $1

param $0
param $1
call list_insert, 2
pop $2
push $2

pop $0
param $0
mema $0, 2
mov $0[0], 1
mov $0[1], 6
push $0

pop $1
param $1
call func_twoSum, 2

pop $0
param $0
call func_print_ans, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
return $0

func_run_tests_END:

jump func_main_END

func_main:
call func_run_tests, 0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
jump EOF

func_main_END:

jump func_main

EOF:
nop
