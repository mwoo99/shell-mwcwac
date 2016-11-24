shelly: proj.c
	gcc proj.c -o shelly

run: shelly
	./shelly

clean:
	rm *~ shelly
