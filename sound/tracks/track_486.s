.align 2

.global track_486

track_486_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 94
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v+29
	.byte N06, Cn1, v127
	.byte W01
	.byte VOL, 91
	.byte W01
	.byte 88 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 81
	.byte W01
	.byte 79 @ VOL
	.byte BEND, c_v+25
	.byte N06 @ Cn1, v127
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+24
	.byte VOL, 76
	.byte W01
	.byte BEND, c_v+21
	.byte VOL, 72
	.byte W01
	.byte BEND, c_v+17
	.byte VOL, 69
	.byte W01
	.byte BEND, c_v+11
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v+3
	.byte VOL, 62
	.byte W01
	.byte BEND, c_v-11
	.byte VOL, 58
	.byte N06 @ Cn1, v127
	.byte W01
	.byte BEND, c_v-21
	.byte VOL, 55
	.byte W01
	.byte BEND, c_v-28
	.byte VOL, 49
	.byte W01
	.byte BEND, c_v-34
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v-38
	.byte VOL, 32
	.byte W01
	.byte BEND, c_v-41
	.byte VOL, 23
	.byte W07
	.byte FINE

track_486_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, En3, v127
	.byte W24
	.byte FINE

.align 2

track_486:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word 0x80a81e8
	.word track_486_0
	.word track_486_1

.align 2
