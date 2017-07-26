.name "test"
.comment "no_live"


l2:
	ld %0, r2
	fork %:l2
