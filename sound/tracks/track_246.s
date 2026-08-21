.align 2

.global track_246

track_246_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 34
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-49
	.byte N36, Gn3, v127
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v+4
	.byte W02
	.byte VOL, 49
	.byte W01
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte 52 @ VOL
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v+43
	.byte W02
	.byte VOL, 45
	.byte W01
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 18
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v-27
	.byte W02
	.byte VOL, 9
	.byte BEND, c_v-37
	.byte W02
	.byte VOL, 7
	.byte BEND, c_v-44
	.byte W02
	.byte VOL, 5
	.byte BEND, c_v-51
	.byte W02
	.byte c_v-57 @ BEND
	.byte W01
	.byte VOL, 4
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_246:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a6af0
	.word track_246_0

.align 2
