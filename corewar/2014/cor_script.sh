make -C .. ;
mv ../asm . ;
rm -rf *.cor ;
for file in ./*	
do
	./asm $file ;
	corfile1=$(basename "$file" .s) ;
	corfile1+=".cor" ;
	hexdump $corfile1 > comp1 ; 
	./example_asm $file ; 
	corfile2=$(basename "$file" .s) ;
	corfile2+=".cor" ;
	hexdump $corfile2 > comp2 ; 
	diff comp1 comp2
done
