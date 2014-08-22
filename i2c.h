#ifndef SDA
	#define SDA 3
#endif
#ifndef SCL
	#define SCL 2
#endif

#ifndef _I2C_H
#define _I2C_H

#include <stdio.h>
#include <unistd.h>
#include <gpio.h>
#include <termios.h>
#include <fcntl.h>
#include <gpio.h>
#define i2c_sleep 4

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
unsigned char i2c_write(unsigned char data);
unsigned char i2c_read(unsigned char ack);
void i2c_close(void);

#endif
