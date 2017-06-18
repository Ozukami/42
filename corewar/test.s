.comment"comment"
.name"name"

label:						#lol
	sti r1,%:loop,%1		#lol
	ldi %:loop,%0,r2
	sti r2,%:label,%-400
	ldi %:loop,%4,r3
	#ld :loop,r2
	sti r3,%:label,%-396
	and %:loop,r2,r2		##XDQHIU
	fork %:carry			;mdrliom
	ld %0,r3#lolefwf

jump:
	zjmp %-500

carry:
	add r4,r5,r6
	add r4,r5,r6

loop:
	live %1
	zjmp%:loop

