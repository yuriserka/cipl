.table

char str_nil[] = "nil"

.code
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

main:
mema $0, 2
mov $0[0], 1
mov $0[1], 1
push $0

mema $0, 2
mov $0[0], 1
mov $0[1], 2
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

mema $0, 2
mov $0[0], 1
mov $0[1], 3
push $0

mema $0, 2
mov $0[0], 2
mov $0[1], 4.000000
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

inttofl $2, $2

mul $3, $2, $3

mema $2, 2
mov $2[0], 2
mov $2[1], $3
push $2

mema $0, 2
mov $0[0], 1
mov $0[1], 5
push $0

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

inttofl $3, $3

div $3, $2, $3

mema $2, 2
mov $2[0], 2
mov $2[1], $3
push $2

pop $1

pop $0

param $0
call get_var_val, 1
pop $2

param $1
call get_var_val, 1
pop $3

inttofl $2, $2

sub $3, $2, $3

mema $2, 2
mov $2[0], 2
mov $2[1], $3
push $2

pop $0
param $0
call writeln, 1

jump EOF

EOF:
nop
