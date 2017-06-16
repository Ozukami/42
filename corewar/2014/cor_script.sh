make -C .. ;
mv ../asm . ;
rm -rf *.cor ;
for file in ./*	
do
	./asm $file ;
	hexdump .cor > comp1 ; 
	./example_asm $file ; 
	corfile=$(basename "$file" .s) ;
	corfile+=".cor" ;
	hexdump $corfile > comp2 ; 
	diff comp1 comp2
done
