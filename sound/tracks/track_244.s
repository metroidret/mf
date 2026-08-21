.align 2

.global track_244

track_244_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 30
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 14
	.byte VOL, 11
	.byte N04 @ Cn3, v127
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte VOICE, 35
	.byte N05, Dn3 @ v127
	.byte W05
	.byte Dn3, v068 @ N05
	.byte W05
	.byte Dn3, v028 @ N05
	.byte W05
	.byte FINE

.align 2

track_244:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a6af0
	.word track_244_0

.align 2
