.table
.code
read:
println 3
return 0

write:
println 1
return 0

writeln:
call write, 0
println
return 0

func:
mov $0, 0
return $0

main:
jump EOF

EOF:
nop
