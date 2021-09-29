.table

.code

func:
    println #0
    pop $0
    return $0

main:
    mov $0, 123.123
    param $0
    call func, 1
    println 10
