.align 2

.global track_149

track_149_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 21
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v
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
	.byte 29 @ VOL
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_149:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a682c
	.word track_149_0

.align 2
