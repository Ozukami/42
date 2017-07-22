.name "test"
.comment "incomplete op"

	#ld	%1908, r4
	#ld	%116, r4
	#ld	%29703, r4
	or 2, 2, r3
	ld	%7604084, r4
	sti r4, %:end, %256
	ld	%16843520, r4
	sti r4, %:end, %260

end:
	live %1
	zjmp %:end
