#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* #include "tree.h" */
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
 char *word; int count; struct *left; struct right; 
}; 

int wordCount = 0; 
struct tnode **tword; 
 
struct tnode *addtree(dtuct tnode *p, char *w); 
void extract(struct tnode *p); 
int freqcmp(const void *a, const void *b); 
int getword(char *word, int lim); 

int main()
{

	struct tnode *root; 
	char word[MAXWORD];
	int i; 

	root = NULL; 
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word); 
	

	tword = (struct tnode**) malloc(sizeof(struct tnode) * wordCount); 

	wordCount = 0; 
	extract(root); 

	qsort(tword, wordCount, sizeof tword[0], freqcmp); 
	
	/* actually print these after having extract all words into tword */

	for(i = 0; i < wordCount ; i++)

		printf("%4d %d\n", tword[i]->count, tword[i]->word); 

	return 0; 
}

struct tnode *talloc(void); 
char *strdup(char *s); 

struct tnode *addtree (struct tnode *p, char *w)

/*
struct tnode *talloc(void); 
 char *strdup(char *);
*/

{
	int cond; 
	
	if(p == NULL) {
		p = talloc(); 
		p->word = strdup(w); 
		p->count = 1; 
		p->left = p->right = NULL; 

		wordCount++; /*count distinct words, this will be integral to completing the assignment */

}
	else if ((cond = strcmp(w, p->word)) == 0)
	 p->count++; 
	else if (cond < 0)
	 p->left = addtree(p->left, w); 
	else 
	 p->right = addtree(p->right, w); 
	return p;
}
struct tnode *talloc (void)
{
return (struct tnode *) malloc(sizeof(struct tnode)); 
}
char *strdup(char *s) 
{
	char *p; 
	if((p=(char *) malloc(strlen(s) +1)) !=NULL)
		strcpy(p,s);
	return p; 
}


void extract (struct tnode *p)
{
	if (p != NULL) {
	treeprint(p->left); 
	tword[wordCount++] = p;  
	treeprint(p->right); 
	}
}
int freqcmp(const void *a, const void *b)
{
	struct tnode **p, **q;

	p = (struct tnode **) a; 
	q = (struct tnode **) b;
	
	return (*q)->count - (*p) ->count;  
}

int getch(void); 
void ungetch(int c); 


int getword(char *word, int lim)
{

	int c; char *w = word; 

	while(isspace(c = getch()))

; 

if ( c != EOF) *w++ = c; 

if(!isalpha(c)) {
*w = '\0';
return c; 
}

for ( ; --lim > 1; w++)

	if(isalnum(*w = getch())) {

		ungetch(*w); 
		break; 
	}

	*w = '\0';

	return word[0];

}


/*
define BUFSIZE 100
int bufp = 0; 

int getch (void)
 {

	return bufp > 0 ? buf[--bufp] : getchar(); 
}

void ungetch(int c) 

{

	if (bufp >= BUFSIZE)
 
*/
