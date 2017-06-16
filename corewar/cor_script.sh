./asm champs/championships/2014/$1.s ;
hexdump champs/championships/2014/$1.cor > comp1 ; 
./example_asm champs/championships/2014/$1.s ; 
hexdump champs/championships/2014/$1.cor > comp2 ; 
diff comp1 comp2
