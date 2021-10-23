.table

char str_nil[] = "nil"
int list_nil[] = {3, 0}
char str_0[] = "computed: "
char str_1[] = "answer:   01011100010100111001011011010100"

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

jump func_main_END

func_main:
mema $0, 2
mov $0[0], 3
mov $0[1], &str_0
push $0

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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

sleq $4, $3, $2
seq $5, $3, $2
not $5, $5
and $3, $4, $5

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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

slt $4, $2, $3
not $3, $4

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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

slt $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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

sleq $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

sleq $4, $3, $2
seq $5, $3, $2
not $5, $5
and $3, $4, $5

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

slt $4, $2, $3
not $3, $4

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

slt $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

sleq $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

sleq $4, $3, $2
seq $5, $3, $2
not $5, $5
and $3, $4, $5

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

slt $4, $2, $3
not $3, $4

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

slt $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

sleq $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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

sleq $4, $3, $2
seq $5, $3, $2
not $5, $5
and $3, $4, $5

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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

slt $4, $2, $3
not $3, $4

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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

slt $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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

sleq $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
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
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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

and $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

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

or $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

and $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

or $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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

and $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

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

or $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

and $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call write, 1

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 0
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

or $3, $2, $3

param $3
call set_bool, 1
pop $3

mema $2, 2
mov $2[0], 1
mov $2[1], $3
push $2

pop $0
param $0
call writeln, 1

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
push $0

pop $0
jump EOF

func_main_END:

jump func_main

EOF:
nop
