.name "BtZ"
.comment "A simple Zork killer"

sti		r1, %28, %1
and		%0, %0, r16
live	%1
live	%1
fork	%3
live	%1
zjmp	%500
