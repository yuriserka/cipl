.table

char str_nil[] = "nil"
char str_0[] = "cmp: "
char str_1[] = "ans: 000000001000001110111111100011111"

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

jump func_main_END

func_main:
// local var int list a
mema $0, 3
mov $0[0], 4
mov $0[1], 0
mema $3, 0
mov $0[2], $3

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 2
push $2

mema $2, 3
mov $2[0], 3
mov $2[1], 0
mema $3, 0
mov $2[2], $3
push $2

pop $2

pop $3

param $2
param $3
call list_insert, 2
pop $4
push $4

pop $2

pop $3

param $2
param $3
call list_insert, 2
pop $4
push $4

pop $2
param $0
param $2
call set_var_val, 2

// local var int list b
mema $1, 3
mov $1[0], 4
mov $1[1], 0
mema $3, 0
mov $1[2], $3

push $0

pop $2

param $2
call list_tail, 1
pop $2
push $2

pop $2

param $2
call list_tail, 1
pop $2
push $2

pop $2
param $1
param $2
call set_var_val, 2

mema $2, 2
mov $2[0], 3
mov $2[1], &str_0
push $2

pop $2
param $2
call write, 1

push $1

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L0, $3
push $1

pop $2

param $2
call list_head, 1
pop $2
push $2

jump main_LAZY_EVAL_L0_END
main_LAZY_EVAL_L0:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L0_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L1, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L2, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L2_END
main_LAZY_EVAL_L2:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L2_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L1_END
main_LAZY_EVAL_L1:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L1_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L3, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L4, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L4_END
main_LAZY_EVAL_L4:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L4_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L3_END
main_LAZY_EVAL_L3:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L3_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L5, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L6, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L6_END
main_LAZY_EVAL_L6:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L6_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L5_END
main_LAZY_EVAL_L5:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L5_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L7, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L8, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L8_END
main_LAZY_EVAL_L8:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L8_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L7_END
main_LAZY_EVAL_L7:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L7_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L9, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L10, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L10_END
main_LAZY_EVAL_L10:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L10_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L9_END
main_LAZY_EVAL_L9:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L9_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L11, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L12, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L12_END
main_LAZY_EVAL_L12:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L12_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L11_END
main_LAZY_EVAL_L11:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L11_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L13, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L14, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L14_END
main_LAZY_EVAL_L14:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L14_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L13_END
main_LAZY_EVAL_L13:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L13_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L15, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L16, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L16_END
main_LAZY_EVAL_L16:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L16_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L15_END
main_LAZY_EVAL_L15:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L15_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L17, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L18, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L18_END
main_LAZY_EVAL_L18:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L18_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L17_END
main_LAZY_EVAL_L17:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L17_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L19, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L20, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L20_END
main_LAZY_EVAL_L20:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L20_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L19_END
main_LAZY_EVAL_L19:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L19_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L21, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L22, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L22_END
main_LAZY_EVAL_L22:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L22_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L21_END
main_LAZY_EVAL_L21:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L21_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L23, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L24, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L24_END
main_LAZY_EVAL_L24:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L24_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L23_END
main_LAZY_EVAL_L23:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L23_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L25, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L26, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L26_END
main_LAZY_EVAL_L26:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L26_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L25_END
main_LAZY_EVAL_L25:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L25_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L27, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L28, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L28_END
main_LAZY_EVAL_L28:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L28_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L27_END
main_LAZY_EVAL_L27:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L27_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L29, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L30, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L30_END
main_LAZY_EVAL_L30:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L30_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L29_END
main_LAZY_EVAL_L29:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L29_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L31, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L32, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L32_END
main_LAZY_EVAL_L32:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L32_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L31_END
main_LAZY_EVAL_L31:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L31_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L33, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L34, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L34_END
main_LAZY_EVAL_L34:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L34_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L33_END
main_LAZY_EVAL_L33:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L33_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L35, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L36, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L36_END
main_LAZY_EVAL_L36:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L36_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L35_END
main_LAZY_EVAL_L35:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L35_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L37, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L38, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L38_END
main_LAZY_EVAL_L38:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L38_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L37_END
main_LAZY_EVAL_L37:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L37_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L39, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L40, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L40_END
main_LAZY_EVAL_L40:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L40_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L39_END
main_LAZY_EVAL_L39:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L39_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L41, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L42, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L42_END
main_LAZY_EVAL_L42:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L42_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L41_END
main_LAZY_EVAL_L41:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L41_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L43, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L44, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L44_END
main_LAZY_EVAL_L44:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L44_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L43_END
main_LAZY_EVAL_L43:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L43_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L45, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L46, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L46_END
main_LAZY_EVAL_L46:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L46_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L45_END
main_LAZY_EVAL_L45:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L45_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L47, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L48, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L48_END
main_LAZY_EVAL_L48:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L48_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L47_END
main_LAZY_EVAL_L47:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L47_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L49, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L50, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L50_END
main_LAZY_EVAL_L50:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L50_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L49_END
main_LAZY_EVAL_L49:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L49_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L51, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L52, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L52_END
main_LAZY_EVAL_L52:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L52_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L51_END
main_LAZY_EVAL_L51:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L51_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L53, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L54, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L54_END
main_LAZY_EVAL_L54:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L54_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L53_END
main_LAZY_EVAL_L53:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L53_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L55, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L56, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L56_END
main_LAZY_EVAL_L56:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L56_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L55_END
main_LAZY_EVAL_L55:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L55_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L57, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L58, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L58_END
main_LAZY_EVAL_L58:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L58_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L57_END
main_LAZY_EVAL_L57:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L57_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L59, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L60, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L60_END
main_LAZY_EVAL_L60:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L60_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L59_END
main_LAZY_EVAL_L59:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L59_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L61, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brz main_LAZY_EVAL_L62, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

jump main_LAZY_EVAL_L62_END
main_LAZY_EVAL_L62:
mema $3, 2
mov $3[0], 1
mov $3[1], 0
push $3
main_LAZY_EVAL_L62_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

and $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L61_END
main_LAZY_EVAL_L61:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L61_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L63, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

pop $2
param $2
call get_var_val, 1
pop $3
param $3
call set_bool, 1
pop $3

brnz main_LAZY_EVAL_L64, $3
mema $2, 2
mov $2[0], 1
mov $2[1], 1
push $2

jump main_LAZY_EVAL_L64_END
main_LAZY_EVAL_L64:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L64_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
pop $5

or $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

jump main_LAZY_EVAL_L63_END
main_LAZY_EVAL_L63:
mema $3, 2
mov $3[0], 1
mov $3[1], 1
push $3
main_LAZY_EVAL_L63_END:
pop $3

param $2
call get_var_val, 1
pop $4
param $4
call set_bool, 1
pop $4

param $3
call get_var_val, 1
pop $5
param $5
call set_bool, 1
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
call writeln, 1

mema $2, 2
mov $2[0], 3
mov $2[1], &str_1
push $2

pop $2
param $2
call writeln, 1

jump EOF

func_main_END:

jump func_main

EOF:
nop
