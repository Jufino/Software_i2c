#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#define SDA 3
#define SCL 2
#define DeviceAddress 0x10
#define Register      0x01
#define Data	      0x50

int main(void)
{
        i2c_init();
      	i2c_start();
        i2c_write(DeviceAddress);
        i2c_write(Register);
	i2c_write(Data);
        i2c_stop();
        i2c_close();
}
