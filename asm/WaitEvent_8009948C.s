	opt	c+, at+, e+, n-
	section .text

	xdef WaitEvent_8009948C
WaitEvent_8009948C:
	dw 0x240A00B0 ; 0x8009948C
	dw 0x01400008 ; 0x80099490
	dw 0x2409000A ; 0x80099494
	dw 0x00000000 ; 0x80099498