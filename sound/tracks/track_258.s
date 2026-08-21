.align 2

.global track_258

track_258_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 6
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N16, Gn2, v127
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W11
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-16 @ BEND
	.byte W09
	.byte FINE

track_258_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 18
	.byte PAN, c_v
	.byte N12, Cn4, v068
	.byte W24
	.byte FINE

.align 2

track_258:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_258_0
	.word track_258_1

.align 2
