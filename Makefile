CC=$(CROSS_COMPILE)gcc -g
TARGET=i2c

i2c.o:i2c.c
	$(CC) -c i2c.c

install: i2c.o
	$(CROSS_COMPILE)ar rcs lib$(TARGET).a i2c.o
	install lib$(TARGET).a /usr/lib/lib$(TARGET).a
	install *.h /usr/include/

example: i2cWrite i2cRead

i2cWrite:i2cWrite.c
	$(CC) i2cWrite.c -li2c -lgpio -o i2cWrite

i2cRead:i2cRead.c
	 $(CC) i2cRead.c -li2c -lgpio -o i2cRead
