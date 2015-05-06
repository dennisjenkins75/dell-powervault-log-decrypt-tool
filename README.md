# dell-powervault-log-decrypt-tool
Decrypts system logs from a Dell Powervault 132-T tape library

By Dennis Jenkins (dennis.jenkins.75@gmail.com)

Tool operates as a STDIN/STDOUT filter.

	gcc -Wall -O2 dell-powervault-log-decrypt-tool.c -o devp
	./depv < input.txt > output.txt

The file seems to be encrypted with a very simple Caesar cipher.

Sample input:
{{{
XX:x}{ z~"hhhh8ZU;\CxyxyEh)TTWKCyxxxE
XX:x}{ z"h;,GZ4/;6"h;\I\][hOWWL
XX:x}{ z!"h;;GZ169h"h->8,C.Eh8IOMCxxEh)TTWKC{ E
XX:x}{ z!"h;,GZ169h"h;\I\][hOWWL
}}}

Sample output:
{{{
ppR05382776:    PrmSt[0101] Alloc[1000]
ppR05382777: SD_rLGSN: Status good
ppR05382779: SS_rINQ : EVPD[F] Page[00] Alloc[38]
ppR05382779: SD_rINQ : Status good
}}}
