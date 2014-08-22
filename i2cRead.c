#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define SDA 3 //SDA PIN3
#define SCL 2 //SCL PIN2
#include "i2c.h"

#define DeviceAddress 0x10
#define Register 0x01
int main(void)
{
        i2c_init();
        i2c_start();
        i2c_write(DeviceAddress);
        i2c_write(Register);
 	i2c_start();
        i2c_write(DeviceAddress+1);
        unsigned char hod = i2c_read(1);
        i2c_stop();
        printf("%d\n",hod);
        i2c_close();
}


