.align 2

.global track_485

track_485_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte PRIO, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 10
	.byte BEND, c_v-48
	.byte N15, Cn3, v092
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 72
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 93
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 91
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-48
	.byte W05
	.byte FINE

track_485_1:
	.byte KEYSH, 0
	.byte W02
	.byte VOICE, 5
	.byte VOL, 95
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v+29
	.byte N06, Cn1, v127
	.byte W01
	.byte VOL, 92
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 89
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 81
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v-1
	.byte N06 @ Cn1, v127
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v-6
	.byte VOL, 74
	.byte W01
	.byte BEND, c_v-11
	.byte VOL, 64
	.byte W01
	.byte BEND, c_v-16
	.byte VOL, 54
	.byte W01
	.byte BEND, c_v-20
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v-25
	.byte VOL, 35
	.byte W01
	.byte BEND, c_v-30
	.byte VOL, 32
	.byte N05 @ Cn1, v127
	.byte W01
	.byte BEND, c_v-35
	.byte VOL, 23
	.byte W01
	.byte BEND, c_v-40
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v-45
	.byte VOL, 5
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_485:
	.byte 2
	.byte 0
	.byte 224
	.byte 0
	.word 0x80a81e8
	.word track_485_0
	.word track_485_1

.align 2
