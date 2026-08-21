.align 2

.global track_604

track_604_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 60
	.byte PAN, c_v
	.byte N32, Cn3, v127
	.byte W32
	.byte W03
	.byte FINE

.align 2

track_604:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a7654
	.word track_604_0

.align 2
