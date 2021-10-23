.table

char str_nil[] = "nil"
int list_nil[] = {3, 0}
char str_0[] = "iterative_list_print: ["
char str_1[] = "]"
char str_2[] = "b: ["
char str_3[] = "]"
char str_4[] = ", "
char str_5[] = ", "
char str_6[] = "a is nil so initializing"
char str_7[] = "recursive_list_print: ["
char str_8[] = "]"
char str_9[] = "sum of list a = "
char str_10[] = "something is wrong"
char str_11[] = "sounds bad!"
char str_12[] = ", "
char str_13[] = "internal it is nil as expected"

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
mov #0[2], $0
return $0

main:

jump func_calc_END

func_calc:
// param int a
mema $0, 2
mov $0[0], 1
mov $1, #0[1]
mov $0[1], $1

push $0

mema $1, 2
mov $1[0], 1
mov $1[1], 2
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

sub $4, $3, $4

mema $3, 2
mov $3[0], 1
mov $3[1], $4
push $3

pop $1
return $1

func_calc_END:

jump func_add1f_END

func_add1f:
// param int x
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
mov $1[1], 1.500000
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

pop $1
return $1

func_add1f_END:

jump func_print_list_it_END

func_print_list_it:
// local var int i
mema $0, 2
mov $0[0], 1
mov $0[1], 0

mema $2, 2
mov $2[0], 3
mov $2[1], &str_0
push $2

pop $2
param $2
call write, 1

// local var int list it
mema $1, 3
mov $1[0], 4
mov $1[1], 0
mema $2, 0
mov $1[2], $2

push #0

pop $2
param $1
param $2
call set_var_val, 2

mema $2, 2
mov $2[0], 1
mov $2[1], 0
push $2

pop $2
param $0
param $2
call set_var_val, 2

print_list_it_L0_LOOP:
push $1

mema $2, 3
mov $2[0], 3
mov $2[1], 0
mema $3, 0
mov $2[2], $3
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

seq $5, $4, $5
not $5, $5
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
brnz print_list_it_L0_END, $3
push $1

pop $2

param $2
call list_head, 1
pop $2
push $2

pop $2
param $2
call write, 1

push $1

pop $2

param $2
call list_tail, 1
pop $2
push $2

mema $2, 3
mov $2[0], 3
mov $2[1], 0
mema $3, 0
mov $2[2], $3
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

seq $5, $4, $5
not $5, $5
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
brnz print_list_it_L1_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_12
push $2

pop $2
param $2
call write, 1

jump print_list_it_L1_END
print_list_it_L1_ELSE:
print_list_it_L1_END:
push $1

pop $2

param $2
call list_pop_tail, 1
pop $2
push $2

pop $2
param $1
param $2
call set_var_val, 2

jump print_list_it_L0_LOOP
print_list_it_L0_END:
mema $2, 2
mov $2[0], 3
mov $2[1], &str_1
push $2

pop $2
param $2
call writeln, 1

push $1

mema $2, 3
mov $2[0], 3
mov $2[1], 0
mema $3, 0
mov $2[2], $3
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

seq $5, $4, $5

param $5
call set_bool, 1
pop $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

pop $2
return $2

func_print_list_it_END:

jump func_print_ilist_rec_END

func_print_ilist_rec:
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
brnz print_ilist_rec_L0_ELSE, $1
mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0
jump print_ilist_rec_L0_END
print_ilist_rec_L0_ELSE:
print_ilist_rec_L0_END:
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
brnz print_ilist_rec_L1_ELSE, $1
mema $0, 2
mov $0[0], 3
mov $0[1], &str_4
push $0

pop $0
param $0
call write, 1

jump print_ilist_rec_L1_END
print_ilist_rec_L1_ELSE:
print_ilist_rec_L1_END:
push #0

pop $0

param $0
call list_tail, 1
pop $0
push $0

pop $0
param $0
call func_print_ilist_rec, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0

func_print_ilist_rec_END:

jump func_print_flist_rec_END

func_print_flist_rec:
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
brnz print_flist_rec_L0_ELSE, $1
mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0
jump print_flist_rec_L0_END
print_flist_rec_L0_ELSE:
print_flist_rec_L0_END:
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
brnz print_flist_rec_L1_ELSE, $1
mema $0, 2
mov $0[0], 3
mov $0[1], &str_5
push $0

pop $0
param $0
call write, 1

jump print_flist_rec_L1_END
print_flist_rec_L1_ELSE:
print_flist_rec_L1_END:
push #0

pop $0

param $0
call list_tail, 1
pop $0
push $0

pop $0
param $0
call func_print_flist_rec, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0

func_print_flist_rec_END:

jump func_sum_list_END

func_sum_list:
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
brnz sum_list_L0_ELSE, $1
mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $0
return $0
jump sum_list_L0_END
sum_list_L0_ELSE:
sum_list_L0_END:
push #0

pop $0

param $0
call list_head, 1
pop $0
push $0

push #0

pop $0

param $0
call list_tail, 1
pop $0
push $0

pop $0
param $0
call func_sum_list, 1

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

func_sum_list_END:

jump func_main_END

func_main:
// local var int list a
mema $0, 3
mov $0[0], 4
mov $0[1], 0
mema $1, 0
mov $0[2], $1

push $0

mema $2, 3
mov $2[0], 3
mov $2[1], 0
mema $3, 0
mov $2[2], $3
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

seq $5, $4, $5

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
brnz main_L0_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_6
push $2

pop $2
param $2
call writeln, 1

mema $2, 2
mov $2[0], 2
mov $2[1], 3.450000
push $2

pop $2
param $2
param 1
call cast, 2
pop $2
push $2

mema $2, 2
mov $2[0], 2
mov $2[1], 12.200000
push $2

pop $2
param $2
param 1
call cast, 2
pop $2
push $2

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
mov $2[1], 4
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

mul $5, $4, $5

mema $4, 2
mov $4[0], 1
mov $4[1], $5
push $4

mema $2, 2
mov $2[0], 1
mov $2[1], 7
push $2

mema $2, 2
mov $2[0], 1
mov $2[1], 3
push $2

pop $2

param $2
call get_var_val, 1
pop $2

not $2, $2
mema $3, 2
mov $3[0], 1
mov $3[1], $2
push $3

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

push $0

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

mema $2, 2
mov $2[0], 3
mov $2[1], &str_7
push $2

pop $2
param $2
call write, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 3
push $2

pop $2
param $2
call func_calc, 1

mema $2, 2
mov $2[0], 1
mov $2[1], 33
push $2

push $0

pop $2
param $2
call func_sum_list, 1

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

pop $3

param $2
param $3
call list_insert, 2
pop $4
push $4

pop $2
param $2
call func_print_ilist_rec, 1

mema $2, 2
mov $2[0], 3
mov $2[1], &str_8
push $2

pop $2
param $2
call writeln, 1

mema $2, 2
mov $2[0], 3
mov $2[1], &str_9
push $2

pop $2
param $2
call write, 1

push $0

pop $2
param $2
call func_sum_list, 1

pop $2
param $2
call writeln, 1

push $0

mema $2, 3
mov $2[0], 3
mov $2[1], 0
mema $3, 0
mov $2[2], $3
push $2

pop $3

pop $2

param $2
call get_var_val, 1
pop $4

param $3
call get_var_val, 1
pop $5

seq $5, $4, $5

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
brnz main_L1_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_11
push $2

pop $2
param $2
call writeln, 1

jump main_L1_END
main_L1_ELSE:
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
mov $2[0], 2
mov $2[1], 4.320000
push $2

pop $2
param $2
param 1
call cast, 2
pop $2
push $2

push $0

pop $2

param $2
call list_head, 1
pop $2
push $2

pop $2
param $2
call func_calc, 1

push $0

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

pop $3

param $2
param $3
call list_insert, 2
pop $4
push $4

pop $2
param $2
call func_print_list_it, 1

pop $2

param $2
call get_var_val, 1
pop $3

seq $3, $3, 0
brnz main_L2_ELSE, $3
mema $2, 2
mov $2[0], 3
mov $2[1], &str_13
push $2

pop $2
param $2
call writeln, 1

jump main_L2_END
main_L2_ELSE:
main_L2_END:
main_L1_END:
jump main_L0_END
main_L0_ELSE:
mema $2, 2
mov $2[0], 3
mov $2[1], &str_10
push $2

pop $2
param $2
call writeln, 1

main_L0_END:
// local var float list b
mema $1, 3
mov $1[0], 5
mov $1[1], 0
mema $2, 0
mov $1[2], $2

push $0

pop $2
mema $4, 3
mov $4[0], 4
mov $5, $2[1]
mema $3, $5
func_main_list_for_each_L3_FOR:
mov $5, 0
func_main_list_for_each_L3_LOOP:
mov $6, $2[1]
slt $6, $5, $6
brz func_main_list_for_each_L3_END, $6 
param $2
param $5
call list_peek, 2
pop $6
push $6
pop $6
param $6
call func_calc, 1
pop $6
mov $3[$5], $6
add $5, $5, 1
jump func_main_list_for_each_L3_LOOP
func_main_list_for_each_L3_END:
mov $4[1], $5
mov $4[2], $3
push $4

pop $2
mema $4, 3
mov $4[0], 5
mov $5, $2[1]
mema $3, $5
func_main_list_for_each_L4_FOR:
mov $5, 0
func_main_list_for_each_L4_LOOP:
mov $6, $2[1]
slt $6, $5, $6
brz func_main_list_for_each_L4_END, $6 
param $2
param $5
call list_peek, 2
pop $6
push $6
pop $6
param $6
call func_add1f, 1
pop $6
mov $3[$5], $6
add $5, $5, 1
jump func_main_list_for_each_L4_LOOP
func_main_list_for_each_L4_END:
mov $4[1], $5
mov $4[2], $3
push $4

pop $2
mema $4, 3
mov $4[0], 4
mov $5, $2[1]
mema $3, $5
func_main_list_for_each_L5_FOR:
mov $5, 0
func_main_list_for_each_L5_LOOP:
mov $6, $2[1]
slt $6, $5, $6
brz func_main_list_for_each_L5_END, $6 
param $2
param $5
call list_peek, 2
pop $6
push $6
pop $6
param $6
param 1
call cast, 2
pop $6
push $6

pop $6
param $6
call func_calc, 1
pop $6
mov $3[$5], $6
add $5, $5, 1
jump func_main_list_for_each_L5_LOOP
func_main_list_for_each_L5_END:
mov $4[1], $5
mov $4[2], $3
push $4

pop $2
mema $4, 3
mov $4[0], 5
mov $5, $2[1]
mema $3, $5
func_main_list_for_each_L6_FOR:
mov $5, 0
func_main_list_for_each_L6_LOOP:
mov $6, $2[1]
slt $6, $5, $6
brz func_main_list_for_each_L6_END, $6 
param $2
param $5
call list_peek, 2
pop $6
push $6
pop $6
param $6
call func_add1f, 1
pop $6
mov $3[$5], $6
add $5, $5, 1
jump func_main_list_for_each_L6_LOOP
func_main_list_for_each_L6_END:
mov $4[1], $5
mov $4[2], $3
push $4

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
call func_print_flist_rec, 1

mema $2, 2
mov $2[0], 3
mov $2[1], &str_3
push $2

pop $2
param $2
call writeln, 1

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
