	opt	c+, at+, e+, n-
	section overlay.text

	xdef s15c_800CCD38
s15c_800CCD38:
	dw 0x8C820B28 ; 800CCD38
	dw 0x00000000 ; 800CCD3C
	dw 0x2C420003 ; 800CCD40
	dw 0x14400006 ; 800CCD44
	dw 0x00000000 ; 800CCD48
	dw 0x8C820B70 ; 800CCD4C
	dw 0x00000000 ; 800CCD50
	dw 0x30420001 ; 800CCD54
	dw 0x14400006 ; 800CCD58
	dw 0x24020001 ; 800CCD5C
	dw 0x8C830B28 ; 800CCD60
	dw 0x00001021 ; 800CCD64
	dw 0x24630001 ; 800CCD68
	dw 0x03E00008 ; 800CCD6C
	dw 0xAC830B28 ; 800CCD70
	dw 0x03E00008 ; 800CCD74
	dw 0x00000000 ; 800CCD78
