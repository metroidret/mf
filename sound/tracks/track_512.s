.align 2

.global track_512

track_512_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W02
	.byte VOICE, 80
	.byte VOL, 0
	.byte BENDR, 10
	.byte BEND, c_v
	.byte N22, As1, v012, 52
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte BEND, c_v
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 69
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 92
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 98
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 103
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 109
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 115
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 121
	.byte BEND, c_v+54
	.byte W01
	.byte FINE

track_512_1:
	.byte KEYSH, 0
	.byte VOICE, 82
	.byte VOL, 127
	.byte N02, Cn3, v012
	.byte W24
	.byte FINE

.align 2

track_512:
	.byte 2
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_512_0
	.word track_512_1

.align 2
