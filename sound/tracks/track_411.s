.align 2

.global track_411

track_411_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 74
	.byte VOL, 16
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte N11, Cn4, v127
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-18
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_411:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_411_0

.align 2
