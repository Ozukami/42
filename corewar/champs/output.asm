# 1 "ex.s"
# 1 "<built-in>" 1
# 1 "ex.s" 2
.name "zork"
.comment "just a basic living prog"

l2: sti r1,%:live,%0
 and r1,%0,r1
live: live %1
 zjmp %:live
