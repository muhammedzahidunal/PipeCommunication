all: determinant3x3 kofakhesap2x2 satsutsec

determinant3x3: determinant3x3.c
	gcc determinant3x3.c -o determinant3x3

kofakhesap2x2: kofakhesap2x2.c
	gcc kofakhesap2x2.c -o kofakhesap2x2

satsutsec: satsutsec.c
	gcc satsutsec.c -o satsutsec
