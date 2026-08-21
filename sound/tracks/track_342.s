.align 2

.global track_342

track_342_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 35
	.byte PAN, c_v
	.byte N03, Gn2, v127
	.byte W08
	.byte Fn2 @ N03, v127
	.byte W06
	.byte N01, Gs2 @ v127
	.byte W01
	.byte FINE

.align 2

track_342:
	.byte 1
	.byte 0
	.byte 132
	.byte 0
	.word 0x80a6d54
	.word track_342_0

.align 2
