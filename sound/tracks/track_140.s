.align 2

.global track_140

track_140_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 12
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N28, Cn5, v127
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 28
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 37
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v+37
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v+32
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v+49
	.byte W02
	.byte VOL, 7
	.byte BEND, c_v+54
	.byte W02
	.byte VOL, 4
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 2
	.byte BEND, c_v+48
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v+62
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_140:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a682c
	.word track_140_0

.align 2
