.align 2

.global track_418

track_418_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 31
	.byte PAN, c_v
	.byte N07, Cn3, v100
	.byte W07
	.byte VOICE, 31
	.byte N10, En4, v080
	.byte W02
	.byte VOL, 40
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_418:
	.byte 1
	.byte 0
	.byte 152
	.byte 0
	.word 0x80a6d54
	.word track_418_0

.align 2
