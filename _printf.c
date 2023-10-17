#include "main.h"







int _printf(const char *format, ...)
{
	int charcount = 0;
	va_list args;

	if(*format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while(*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			charcount++;
		}
		else
		{
			switch(*format)
			{
				case "c":

			}
		}
	}
}
