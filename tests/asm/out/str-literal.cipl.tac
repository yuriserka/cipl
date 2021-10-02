.table
char snil[] = "nil"
char str_0[] = "a valid simple str literal"
char str_1[] = ""
char str_2[] = "escaped chars are allowed like: \"this\" and \'that\' or `this`"
char str_3[] = "\twhat about this?\n\n"
char str_4[] = "\ttes\0te"
char str_5[] = "other symbols: ! @ $ % & * (a_) - + ="
char str_6[] = "octal code bacome some printable -> A\072five"
char str_7[] = "same for hexs -> B\x4aLol"
char str_8[] = "multi: \133x\135=\x58^\x59"
char str_9[] = "octal pruned at 3: x\1335\135=\065;"
char str_10[] = "\033[31merror:\033[0m just a joke :D"
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

main:
mov $0, &str_0
param $0
param 0
call writeln, 2
mov $0, &str_1
param $0
param 0
call writeln, 2
mov $0, &str_2
param $0
param 0
call writeln, 2
mov $0, &str_3
param $0
param 0
call writeln, 2
mov $0, &str_4
param $0
param 0
call writeln, 2
mov $0, &str_5
param $0
param 0
call writeln, 2
mov $0, &str_6
param $0
param 0
call writeln, 2
mov $0, &str_7
param $0
param 0
call writeln, 2
mov $0, &str_8
param $0
param 0
call writeln, 2
mov $0, &str_9
param $0
param 0
call writeln, 2
mov $0, &str_10
param $0
param 0
call writeln, 2
jump EOF

EOF:
nop
