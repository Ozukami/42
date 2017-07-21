.name "test"
.comment "incomplete op"

	#ld	%1908, r4
	#ld	%116, r4
	ld	%29703, r4
	sti r4, %:end, %256

end:
	live %1
	zjmp %:end
