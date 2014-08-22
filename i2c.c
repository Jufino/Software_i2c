#include "i2c.h"

void i2c_init(void){//ok
	gpio_open(SCL,1);
	gpio_open(SDA,1);
	gpio_write(SDA,1);
	gpio_write(SCL,1);
}

void i2c_start(void){//ok
	gpio_write(SDA,1);
      gpio_write(SCL,1);
        usleep(i2c_sleep);
	gpio_write(SDA,0);
	usleep(i2c_sleep);
	gpio_write(SCL,0);	
}

void i2c_stop(void){//ok
	gpio_write(SDA,0);
	usleep(i2c_sleep);
	gpio_write(SCL,1);
	usleep(i2c_sleep);
	gpio_write(SDA,1);
	usleep(i2c_sleep);
}

unsigned char i2c_write(unsigned char data){//ok
	unsigned char m;
	for (m = 0x80; m != 0; m >>= 1) {
		if (m & data)	gpio_write(SDA,1);
		else 		gpio_write(SDA,0);
		gpio_write(SCL,1);
		usleep(i2c_sleep);
		gpio_write(SCL,0);
	}
	gpio_dir(SDA,0);
	gpio_write(SDA,1);
	gpio_write(SCL,1);
	unsigned char isOK = gpio_read(SDA);
	gpio_write(SCL,0);
	gpio_dir(SDA,1);
	gpio_write(SDA,0);
	return isOK == 0;
}

unsigned char i2c_read(unsigned char ack){//ok
	unsigned char b = 0;
	gpio_dir(SDA,0);
	gpio_write(SDA,1);
	unsigned char i;
	for (i = 0; i < 8; i++) {
		b <<= 1;
		usleep(i2c_sleep);
		gpio_write(SCL,1);
		if (gpio_read(SDA)) b |= 1;
		gpio_write(SCL,0);
	}
	gpio_write(SDA,0);
	gpio_dir(SDA,1);
	if (ack)	gpio_write(SDA,1); 
	else 		gpio_write(SDA,0);
	gpio_write(SCL,1);
	usleep(i2c_sleep);
	gpio_write(SCL,0);
	gpio_write(SDA,0);
	return b;
}

void i2c_close(void){//ok
	gpio_close(SDA);
	gpio_close(SCL);
}
