.align 2

.global track_661

track_661_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 127
	.byte PAN, c_v
	.byte N36, Cn3, v127
	.byte W24
	.byte VOL, 127
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_661:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7e10
	.word track_661_0

.align 2
