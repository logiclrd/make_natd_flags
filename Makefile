default: all

all: make_natd_flags

make_natd_flags: make_natd_flags.c
	gcc -o make_natd_flags make_natd_flags.c

clean:
	rm -f make_natd_flags

.PHONY: default all clean
