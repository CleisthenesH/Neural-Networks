# Copyright 2023 Kieran W Harvie. All rights reserved.
.PHONY: clean

network: examples/network.c src/network.h src/network.h
	gcc examples/network.c  src/network.h src/network.h -o network -Isrc -lm

dual_number: examples/dual_number.c src/dual_number.h
	gcc examples/dual_number.c src/dual_number.h -o dual_number -Isrc -lm

src/%.o:src/%.c src/%.h
	gcc -c $< -o $@ -Isrc  

clean:
	find . -maxdepth 1 -type f -executable | xargs rm -f
	find src -maxdepth 1 -type f -name "*.o"  | xargs rm -f
