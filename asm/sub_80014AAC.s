	opt	c+, at+, e+, n-
	section .text

	xdef FS_Null_80014AAC
FS_Null_80014AAC:
	dw 0x03E00008 ; 0x80014AAC
	dw 0x00000000 ; 0x80014AB0

	xdef FS_Null_80014AB4
FS_Null_80014AB4:
	dw 0x03E00008 ; 0x80014AB4
	dw 0x00001021 ; 0x80014AB8

	xdef FS_Null_80014ABC
FS_Null_80014ABC:
	dw 0x03E00008 ; 0x80014ABC
	dw 0x00000000 ; 0x80014AC0

	xdef sub_80014AC4
sub_80014AC4:
	dw 0x27BDFFE8 ; 0x80014AC4
	dw 0x00802821 ; 0x80014AC8
	dw 0x3C048001 ; 0x80014ACC
	dw 0xAFBF0010 ; 0x80014AD0
	dw 0x0C022EE8 ; 0x80014AD4
	dw 0x24840028 ; 0x80014AD8
	dw 0x8FBF0010 ; 0x80014ADC
	dw 0x00000000 ; 0x80014AE0
	dw 0x03E00008 ; 0x80014AE4
	dw 0x27BD0018 ; 0x80014AE8

	xdef sub_80014AEC
sub_80014AEC:
	dw 0x27BDFFE8 ; 0x80014AEC
	dw 0x00802821 ; 0x80014AF0
	dw 0x3C048001 ; 0x80014AF4
	dw 0xAFBF0010 ; 0x80014AF8
	dw 0x0C022EE8 ; 0x80014AFC
	dw 0x2484003C ; 0x80014B00
	dw 0x8FBF0010 ; 0x80014B04
	dw 0x00000000 ; 0x80014B08
	dw 0x03E00008 ; 0x80014B0C
	dw 0x27BD0018 ; 0x80014B10

	xdef sub_80014B14
sub_80014B14:
	dw 0x03E00008 ; 0x80014B14
	dw 0x2402FFFF ; 0x80014B18
