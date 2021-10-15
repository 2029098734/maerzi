target = $(wildcard *.c)
cc = gcc
ld = ld

main.exe : $(target)
	$(cc) $(target) -o $@

.pHONY : clean
clean :
	rm *.o *.exe *.map