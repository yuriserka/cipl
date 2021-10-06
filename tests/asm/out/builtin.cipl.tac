.table

char str_nil[] = "nil"
char str_0[] = "whats your age: "
char str_1[] = "i also have "
char str_2[] = " years, thats amazing!"
char str_3[] = "b -> not initialized by read = "
char str_4[] = "later ref of a: "
char str_5[] = "+"
char str_6[] = "a static number: "
char str_7[] = "\033[31merror\033[0m: "
char str_8[] = "list is "

.code
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

main:
// int a
mema $0, 2
mov $0[1], 0
mov *$0, 1

mov $2, &str_0
param $2
param 0
call write, 2

param $0
call read, 1

mov $2, &str_1
param $2
param 0
call write, 2

param $0
param 2
call write, 2

mov $2, &str_2
param $2
param 0
call writeln, 2

// float b
mema $1, 2
mov $1[1], 0.000000
mov *$1, 2

mov $2, &str_3
param $2
param 0
call write, 2

param $1
param 2
call writeln, 2

mov $2, &str_4
param $2
param 0
call write, 2

param $0
param 2
call write, 2

mov $2, &str_5
param $2
param 0
call write, 2

param $0
param 2
call writeln, 2

mov $2, &str_6
param $2
param 0
call write, 2

param 123.214000
param 1
call writeln, 2

mov $2, &str_7
param $2
param 0
call write, 2

mov $2, &str_8
param $2
param 0
call write, 2

mov $2, &str_nil
param $2
param 0
call writeln, 2

jump EOF

EOF:
nop
