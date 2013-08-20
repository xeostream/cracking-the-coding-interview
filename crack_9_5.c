#include <stdio.h>
#include <stdlib.h>

int search(char *[], char *, int, int);

main()
{
	char *s[] = {
		"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
	};
	printf("%d\n", search(s, "ball", 0, 12));
	return 0;
}

int search(char *s[], char *t, int begin, int end)
{
	if (begin <= end) {
		int middle = (begin + end) / 2;
		int temp = middle;
		while (middle <= end && s[middle] == "")
			middle++;
		if (t == s[middle])
			return middle;
		else if (t < s[middle])
			return search(s, t, begin, temp-1);
		else
			return search(s, t, middle+1, end);
	} else
		return -1;	
}