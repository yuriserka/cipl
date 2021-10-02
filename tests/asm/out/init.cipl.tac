.table

char str_nil[] = "nil"
char str_0[] = "hello world"
char str_1[] = "a static number: "
char str_2[] = "\033[31merror\033[0m: "
char str_3[] = "list is "

.code

read:
println 3
return 0

write:
brz write_STR, #1
print #0
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

func:
mov $0, 0
return $0

main:
mov $0, &str_0
param $0
param 0
call writeln, 2

mov $0, &str_1
param $0
param 0
call write, 2

param 123.214000
param 1
call writeln, 2

param 10
param 1
call writeln, 2

mov $0, &str_2
param $0
param 0
call write, 2

mov $0, &str_3
param $0
param 0
call write, 2

mov $0, &str_nil
param $0
param 0
call writeln, 2

jump EOF

EOF:
nop
