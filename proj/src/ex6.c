/*
 * terminal like io, polling mode
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "termio.h"

char buffer[50];

int main()
{
	int c=276;
	term_init(80,24);
	
	term_clrscr();
	
	term_gotoxy(25,5);
	term_color(CL_RED, CL_BRIGHT);
	term_printf("du texte et des nombres (%d) en couleur\n\r", c);
	term_color(CL_DEFAULT, CL_DEFAULT);

	irq_enable();
	
	while (1) {
		readline("some text..? ", buffer, 50);
		term_printf("\r\nthe text is: %s\r\n", buffer);
	}

	return 0;
}

