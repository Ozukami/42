.comment"comment"
.name"name"
label:
sti r1,%:loop,%1
and %:loop,r2,r2
fork %:loop
ld %1,r3
loop:live %1
zjmp%:loop
