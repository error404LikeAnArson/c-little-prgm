#include<stdio.h>
#define N 4

void tirage (char t[N], int n)
{
	int i;
	for (i=0; i<N; i++)
	{
		t[i]=rand()%6;
		switch (t[i])
		{
			case 0: t[i]='R'; break;
			case 1: t[i]='B'; break;
			case 2: t[i]='V'; break;
			case 3: t[i]='J'; break;
			case 4: t[i]='N'; break;
			case 5: t[i]='O'; break;
		}
	}
	return;
}

int main()
{
	char t[N], a, b, c, d, nb=1;
	printf("le jeu du masteurmind\n\n");
	srand(time(0));
	tirage (t, N);
	printf("les couleurs sont R pour rouge\nB pour bleu\nV pour vert\nJ pour jaune\nN pour noir\net O pour orange\n\n");
	printf("donnez votre première tentative de la forme \"X X X X\"\n");
	do
	{
		printf("tentative %d", nb);
		scanf("%c %c %c %c", &a, &b, &c, &d);
		if (a==0)||(b==0)||(c==0)||(d==0)
			printf("erreur de saisie");
		else
		{
			if (a==t[0])
				printf("le premier %c est à la bonne place", a);
			else if ((a==t[1])&&(b!=t[1])||(a==t[2])&&(c!=t[2])||(a==t[3])&&(d!=t[3]))
					printf("le premier %c n'est pas à la bonne place", a);
			if (b==t[1])
				printf("le second %c est a la bonne place", b);
			else if ((b==t[0])&&(a!=t[0])||(b==t[2])&&(c!=t[2])||(b==t[3])&&(d!=t[3]))
					printf("le second %c n'est pas à la bonne place", b);
			if (c==t[2])
				printf("le troisième %c est a la bonne place", c);
			else if ((c==t[0])&&(a!=t[0])||(c==t[1])&&(b!=t[1])||(c==t[3])&&(d!=t[3]))
					printf("le troisième %c n'est pas à la bonne place", c);
			if (d==t[3])
				printf("le quatrième %c est a la bonne place", d);
			else if ((d==t[0])&&(a!=t[0])||(d==t[1])&&(b!=t[1])||(d==t[2])&&(c!=t[2]))
					printf("le quatrième %c n'est pas à la bonne place", d);
		}
		nb++;
	}
	while((a!=t[0])||(b!=t[1])||(c!=t[2])||(d!=t[3]));
	printf("bravo! vous avez trouvé	%c %c %c %c", t[0], t[1], t[2], t[3]);
	return 0;
}
