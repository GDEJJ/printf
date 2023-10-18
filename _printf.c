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

	while (*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			charcount++;
		}
		else
		{
			format++;

			switch(*format)
			{
				case "c":
					char c = va_arg(args, char);
					write(1, &c, 1);
                        		charcount++;
					break;
				case "s":
					char *stn = va_arg(args, char*);
					int slen;

					for (slen = 0; stn[slen] != '\0'; slen++)
						;
					
					write(1, stn, slen);
					charcount += slen;
					break;
				case "%":
					write(1, format, 1);
					break;
				case "d":
					int i = va_arg(args, int);
					write(1, i, 4);
					charcount++;
				default:
					break;
			}
		}

		format++;
	}
	
	va_end(args);

	return charcount;
}
