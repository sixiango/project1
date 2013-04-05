SOURCE=*.c

gba_nds_fs:$(SOURCE)
	gcc -O0 -g -DX86 $(SOURCE) -o $@

all:gba_nds_fs

clean:
	rm *.o gba_nds_fs
