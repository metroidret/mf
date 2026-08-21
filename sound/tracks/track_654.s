.align 2

.global track_654

track_654_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte MOD, 40
	.byte VOL, 50
	.byte PAN, c_v
	.byte LFOS, 100
	.byte PRIO, 3
	.byte N32, Cn3, v127
	.byte W32
	.byte FINE

.align 2

track_654:
	.byte 1
	.byte 0
	.byte 219
	.byte 0
	.word 0x80a7e10
	.word track_654_0

.align 2
