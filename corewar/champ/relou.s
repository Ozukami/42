.name "relou"
.comment "load une val de la mem modifiee pedant le chargement de l'op"

ld		%5454, r3
st		r3, 300
ld		%4242, r3
fork	%:load
lldi	%285, %0, r2
st		r2, -200

load:
st		r3, 273
