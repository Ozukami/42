.name "zork3"
.comment "zork"


#fewofwefwe



#fejfiwe
l2:		sti r1,%:live,%1
		and r1,%0,r1
		live %1
		live %1
		fork %:live

#fejfiwe
live: 	live%1
		zjmp %:live
