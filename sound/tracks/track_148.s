.align 2

.global track_148

track_148_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 50
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v-63
	.byte N24, Gn3, v100
	.byte W02
	.byte VOL, 28
	.byte BEND, c_v-33
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 47
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 37
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 13
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_148:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_148_0

.align 2
