#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	static int *start, *maxstart, *maxend, maxlen, len, d;
	int c;
	if ((c = getchar()) != EOF)
	{
		  if (len == 0)
			  start = &c;

		  if (c == '\n')
		  {
			  if (len > maxlen)
			  {
				  maxlen = len;
				  maxstart = start;
				  maxend = &c;
			  }
			  len = 0;
		  }
		  else
			  ++len;
		  main();
	}
	if (len > maxlen)
	{
		maxlen = len;
		maxstart = start;
		maxend = &c;
	}
	if (maxlen != 0)
	{
		d = ((void *)maxstart - (void *)maxend)/maxlen;
	        for (start = maxstart; start != maxend; start = (void *)start-d)
		putchar(*start);
	}
	puts("");
	exit(0);
}
