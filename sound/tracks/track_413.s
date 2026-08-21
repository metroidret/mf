.align 2

.global track_413

track_413_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 55
	.byte VOL, 9
	.byte PAN, c_v
	.byte W05
	.byte BENDR, 7
	.byte BEND, c_v
	.byte N16, Cn2, v080
	.byte W01
	.byte VOL, 11
	.byte W02
	.byte 13 @ VOL
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 35
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 55
	.byte W01
	.byte BEND, c_v+63
	.byte W40
	.byte VOICE, 41
	.byte N05, En2, v040
	.byte W05
	.byte FINE

.align 2

track_413:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_413_0

.align 2
