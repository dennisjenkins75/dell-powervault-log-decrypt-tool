/*	Tool to decrypt Dell Powervault log files. (Powervault 132T).

	by Dennis Jenkins (dennis.jenkins.75@gmail.com)

	Tool operates as a STDIN/STDOUT filter.

	gcc -Wall -O2 dell-powervault-log-decrypt-tool.c -o devp
	./depv < input.txt > output.txt

	The file seems to be encrypted with a very simple Caesar cipher.


	Sample input:
XX:x}{ z~"hhhh8ZU;\CxyxyEh)TTWKCyxxxE
XX:x}{ z"h;,GZ4/;6"h;\I\][hOWWL
XX:x}{ z!"h;;GZ169h"h->8,C.Eh8IOMCxxEh)TTWKC{ E
XX:x}{ z!"h;,GZ169h"h;\I\][hOWWL

	Sample output:
ppR05382776:    PrmSt[0101] Alloc[1000]
ppR05382777: SD_rLGSN: Status good
ppR05382779: SS_rINQ : EVPD[F] Page[00] Alloc[38]
ppR05382779: SD_rINQ : Status good

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char *argv[])
{
	char	buff[256];
	int		len = 0;
	int		i;

	while (fgets(buff, sizeof(buff), stdin))
	{
		if (0 > (len = strlen(buff)))
		{
			continue;
		}

		buff[--len] = 0;		// remove '\n' from line.

		for (i = 0; buff[i]; i++)
		{
			char n = (((buff[i] - ' ') + 0x78) % 96) + ' ';

			printf("%c", n);
		}

		printf("\n");
	}

	return 0;
}
