.comment"comment"
.name"name"
sti r1,%:loop,%1
and 0,r2,r2
fork %:loop
ld %1,r3
loop:live %1
zjmp%:loop
