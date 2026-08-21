.align 2

.global track_151

track_151_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 50
	.byte VOL, 21
	.byte PAN, c_v
	.byte N24, Cn4, v100
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_151:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_151_0

.align 2
