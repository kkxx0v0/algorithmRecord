#include<stdio.h>
using namespace std;
char s[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		int i;
		for (i = 0; s[i] && s[i] != c; i++);
		if (s[i])
			putchar(s[i - 1]);
		else
			putchar(c);
	}
	return 0;
}