
int test_led(int argc, char *argv[])
{
	int		fd;
	int		ret = 0;

	fd = xxx_open(LED0_DEVICE_PATH, 0);

	if (fd < 0) {
		printf("\tLED: open fail\n");
		return ERROR;
	}

	if (xxx_ioctl(fd, LED_ON, LED_BLUE) ||
	    xxx_ioctl(fd, LED_ON, LED_AMBER)) {

		printf("\tLED: ioctl fail\n");
		return ERROR;
	}

	/* let them blink for fun */

	int i;
	uint8_t ledon = 1;

	for (i = 0; i < 10; i++) {
		if (ledon) {
			xxx_ioctl(fd, LED_ON, LED_BLUE);
			xxx_ioctl(fd, LED_OFF, LED_AMBER);

		} else {
			xxx_ioctl(fd, LED_OFF, LED_BLUE);
			xxx_ioctl(fd, LED_ON, LED_AMBER);
		}

		ledon = !ledon;
		usleep(60000);
	}

	/* Go back to default */
	xxx_ioctl(fd, LED_ON, LED_BLUE);
	xxx_ioctl(fd, LED_OFF, LED_AMBER);

	printf("\t LED test completed, no errors.\n");

	return ret;
}
