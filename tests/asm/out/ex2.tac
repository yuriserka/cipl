.table

char str_nil[] = "nil"
int list_nil[] = {3, 0}
char str_0[] = "w_("
char str_1[] = "): "

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
mov $1[0], #1
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

jump func_compute_w_END

func_compute_w:
// param int elem
mema $0, 2
mov $0[0], 1
mov $1, #0[1]
mov $0[1], $1

push $0

pop $1
param $1
param 2
call cast, 2
pop $1
push $1

mema $1, 2
mov $1[0], 2
mov $1[1], 4.300000
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

div $4, $3, $4

mema $3, 2
mov $3[0], 2
mov $3[1], $4
push $3

pop $1
return $1

func_compute_w_END:

jump func_main_END

func_main:
// local var int list l
mema $0, 3
mov $0[0], 4
mov $0[1], 0
mema $7, 0
mov $0[2], $7

// local var int n
mema $1, 2
mov $1[0], 1
mov $1[1], 0

push $1

pop $6
param $6
call read, 1

// local var int i
mema $2, 2
mov $2[0], 1
mov $2[1], 0

// local var int elem
mema $3, 2
mov $3[0], 1
mov $3[1], 0

mema $6, 2
mov $6[0], 1
mov $6[1], 0
push $6

pop $6
param $2
param $6
call set_var_val, 2

main_L0_LOOP:
push $2

push $1

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

brnz main_L0_END, $7
push $3

pop $6
param $6
call read, 1

push $3

push $0

pop $6

pop $7

param $6
param $7
call list_insert, 2
pop $8
push $8

pop $6
param $0
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

jump main_L0_LOOP
main_L0_END:
// local var float list w
mema $4, 3
mov $4[0], 5
mov $4[1], 0
mema $7, 0
mov $4[2], $7

// local var float list it
mema $5, 3
mov $5[0], 5
mov $5[1], 0
mema $7, 0
mov $5[2], $7

push $0

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
call func_compute_w, 1
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
param $4
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

push $4

pop $6
param $5
param $6
call set_var_val, 2

main_L2_LOOP:
push $5

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

brnz main_L2_END, $7
mema $6, 2
mov $6[0], 3
mov $6[1], &str_0
push $6

pop $6
param $6
call write, 1

push $2

pop $6
param $6
call write, 1

mema $6, 2
mov $6[0], 3
mov $6[1], &str_1
push $6

pop $6
param $6
call write, 1

push $5

pop $6

param $6
call list_head, 1
pop $6
push $6

pop $6
param $6
call writeln, 1

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

push $5

pop $6

param $6
call list_tail, 1
pop $6
push $6

pop $6
param $5
param $6
call set_var_val, 2

jump main_L2_LOOP
main_L2_END:
push $5

pop $6

param $6
call list_pop_tail, 1
pop $6
push $6

pop $6
param $5
param $6
call set_var_val, 2

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
