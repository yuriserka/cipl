.table

char str_nil[] = "nil"
char str_0[] = "a in fn: "
char str_1[] = "b in fn: "
char str_2[] = "a in main: "
char str_3[] = "b in main: "
char str_4[] = "a in main after: "
char str_5[] = "a func call inside -> "

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
brz write_STR, #1
seq $0, #1, 1
brz write_VAR, $0
print #0
jump write_END
write_VAR:
param #0
call get_var_val, 1
pop $0
print $0
jump write_END
write_STR:
mov $2, 0
write_STR_LOOP:
mov $1, '\0'
mov $3, #0[$2]
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

func_fn:
// param int a
mema $1, 2
mov $2, #0[1]
mov $1[1], $2
mov *$1, 1

// var float b
mema $0, 2
mov $0[1], 0.000000
mov *$0, 2

param $1
call read, 1

param $0
call read, 1

mov $2, &str_0
param $2
param 0
call write, 2

param $1
param 2
call writeln, 2

mov $2, &str_1
param $2
param 0
call write, 2

param $0
param 2
call writeln, 2

mov $1, $0
return $1

func_fn2:
mov $0, 3.141590
return $0

main:
// var int a
mema $0, 2
mov $0[1], 0
mov *$0, 1

// var float b
mema $1, 2
mov $1[1], 0.000000
mov *$1, 2

param $0
call func_fn, 1
pop $2

param $1
param $2
param 1
call set_var_val, 3

mov $2, &str_2
param $2
param 0
call write, 2

param $0
param 2
call writeln, 2

mov $2, &str_3
param $2
param 0
call write, 2

param $1
param 2
call writeln, 2

mov $1, $1
param $0
param $1
param 1
call set_var_val, 3

mov $2, &str_4
param $2
param 0
call write, 2

param $0
param 2
call writeln, 2

mov $2, &str_5
param $2
param 0
call write, 2

call func_fn2, 0
pop $2

param $2
param 1
call writeln, 2

jump EOF

EOF:
nop
