static void print_usage(void)
{
	PRINT_MODULE_DESCRIPTION("Reboot the system");

	PRINT_MODULE_USAGE_NAME_SIMPLE("reboot", "command");
	PRINT_MODULE_USAGE_PARAM_FLAG('b', "Reboot into bootloader", true);

	PRINT_MODULE_USAGE_ARG("lock|unlock", "Take/release the shutdown lock (for testing)", true);
}

int reboot_main(int argc, char *argv[])
{
	int ch;
	bool to_bootloader = false;

	int myoptind = 1;
	const char *myoptarg = NULL;

	while ((ch = xxx_getopt(argc, argv, "b", &myoptind, &myoptarg)) != -1) {
		switch (ch) {
		case 'b':
			to_bootloader = true;
			break;

		default:
			print_usage();
			return 1;

		}
	}

	if (myoptind >= 0 && myoptind < argc) {
		int ret = -1;

		if (strcmp(argv[myoptind], "lock") == 0) {
			ret = xxx_shutdown_lock();

			if (ret != 0) {
				XXX_ERR("lock failed (%i)", ret);
			}
		}

		if (strcmp(argv[myoptind], "unlock") == 0) {
			ret = px4_shutdown_unlock();

			if (ret != 0) {
				XXX_ERR("unlock failed (%i)", ret);
			}
		}

		return ret;
	}

	int ret = XXX_shutdown_request(true, to_bootloader);

	if (ret < 0) {
		XXX_ERR("reboot failed (%i)", ret);
		return -1;
	}

	while (1) { usleep(1); } // this command should not return on success

	return 0;
}

