.align 2

.global track_412

track_412_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 74
	.byte VOL, 56
	.byte PAN, c_v
	.byte N10, Cn4, v120
	.byte W02
	.byte VOL, 60
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte VOICE, 75
	.byte BENDR, 20
	.byte BEND, c_v
	.byte N10, Gn3, v127
	.byte W02
	.byte VOL, 61
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 52
	.byte W02
	.byte 36 @ VOL
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 14
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_412:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_412_0

.align 2
