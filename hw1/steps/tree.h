struct tnode {
char *word;
int count;
struct tnode *left;
struct tnode *right;
};

struct tnode *left;
struct t {
struct s *p;
};

struct s {
struct t *q;
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *); 
void treeprint(struct tnode *);
int getword(char *, int); 
