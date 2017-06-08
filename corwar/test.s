.name "test"
.comment "test"

init:	sti r1,%:loop,%1
		and r1,%0,r1
		fork %:loop
		ld %72,r3

loop:	live %1
		zjmp %:loop
