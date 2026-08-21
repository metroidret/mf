.align 2

.global track_386

track_386_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 63
	.byte MOD, 50
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N30, Cn3, v080
	.byte W02
	.byte VOL, 6
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W17
	.byte 25 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_386:
	.byte 1
	.byte 0
	.byte 150
	.byte 0
	.word 0x80a6d54
	.word track_386_0

.align 2
