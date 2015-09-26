typedef struct No{
	int num;
	struct No *anterior;
}no;

typedef struct Pilha{
	no *topo;
	int tamanho;
}pilha;

void inicia(pilha *p);
void empty(pilha *p);
void insertNum(pilha *p, int num);
int getNum(pilha *p);
