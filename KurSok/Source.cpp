#include "stdio.h";
#include "math.h";

struct Novels
{
	int pages;
	int nTom;
};

int MaxPages = 600;

void Group(struct Novels*, int*, int, int);

int main()
{
	int N, i, j;
	float sum = 0;
	int Q;
	struct Novels *n;
	int* tomC;
	printf("Enter count of novels: ");
	while (!scanf("%d", &N))
	{
		printf("\nError.Repeat\n");
		getchar();
	}
	n = new struct Novels[N];
	for (i = 0; i < N; i++)
	{
		printf("Enter count of pages: ");
		while (!scanf("%d", &n[i].pages))
		{
			
			printf("\nError.Repeat\n.");
			getchar();
		}
		while ((n[i].pages > MaxPages) || (n[i].pages<0))
		{
			printf("\nNovel is too big,we can not sort it,repeat entered\n");
			printf("Enter count of pages: ");
			scanf("%d", &n[i].pages);
		}
		n[i].nTom = -1;
		sum += n[i].pages;

	}
	for (i = 0; i < N; i++)
	{
		printf("%d) novel's pages:%d \n", i, n[i].pages);
	}
	printf("\n");
	Q = ceil(sum / MaxPages);
	printf("\n%d\n",Q);
	tomC = new int[Q];
	for (i = 0; i < Q; i++)
	{
		tomC[i] = 0;
	}
	Group(n, tomC, N, Q);
	return 0;
}

void Group(struct Novels* n, int* tomC, int N, int Q)
{
	int j1 = 0;
	for (int l = 0; l < N; l++)
	{
		for (int l1 = l+1;l1 < N;l1++)
	    {
			if ((n[l].pages + n[l1].pages) == MaxPages)
			{
				tomC[j1] = MaxPages;
				n[l].pages = n[l].pages*(-1);
				n[l1].pages = n[l1].pages*(-1);
				n[l].nTom = j1;
				n[l1].nTom = j1;
				j1++;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		int j = j1;
		while (j < Q)
		{
			if (n[i].pages <= (MaxPages - tomC[j]) && (n[i].pages>0))
			{
				n[i].nTom = j;
				tomC[j] += n[i].pages;
				j = Q;
			}
			else
			{
				j++;
			}
		}
	}
	
	for (int k = 0; k < Q; k++)
	{
		printf("%d) Tom (%d pages)", k, tomC[k]);
		for (int j = 0; j < N; j++)
			if (k == n[j].nTom)
				printf("%d novel ", j);
		printf("\n");
	}

}
