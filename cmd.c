#include "shell.h"
/**
 * cmd - Checks the mode type
 * @file_descriptor: file descriptor
 * @buf: buffer
**/
void cmd(int file_descriptor, struct stat buf)
{
	fstat(file_descriptor, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts("DM$ ");
}

