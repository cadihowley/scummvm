#include <stdlib.h>
#include <string.h>

#include "grammar.h"
#include "grammar.tab.h"

static Symbol *symlist = 0;  /* symbol table: linked list */

Symbol *lookup(char *s)	/* find s in symbol table */
{
	Symbol *sp;

	for (sp = symlist; sp != (Symbol *) 0; sp = sp->next)
		if (strcmp(sp->name, s) == 0)
			return sp;
	return 0;	/* 0 ==> not found */	
}

Symbol *install(char *n, int t, int d, char *s)  /* install s in symbol table */
{
	Symbol *sp;
	char *emalloc();

	sp = (Symbol *) emalloc(sizeof(Symbol));
	sp->name = emalloc(strlen(n)+1); /* +1 for '\0' */
	strcpy(sp->name, n);
	sp->type = t;
	if (t == NUM || t == NAME)
	   sp->u.val = d;
	else if (t == STRING)
	   sp->u.str = s;
        else
	   abort();

	sp->next = symlist; /* put at front of list */
	symlist = sp;
	return sp;
}

char *emalloc(unsigned n)	/* check return from malloc */
{
	char *p;

	p = (char*) malloc(n);
	if (p == 0)
		abort(); //execerror("out of memory", (char *) 0);
	return p;
}