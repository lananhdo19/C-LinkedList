#Lan Anh Do  
.SUFFIXES: .o .c

linkedlist: linkedlist.c
	clang -o linkedlist linkedlist.c
	

clean:
	-rm -f *.o *~ output
	

