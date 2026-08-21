.align 2

.global track_445

track_445_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 97
	.byte VOL, 49
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v+32
	.byte N21, Cn4, v100
	.byte W03
	.byte VOL, 48
	.byte BEND, c_v+23
	.byte W03
	.byte VOL, 45
	.byte BEND, c_v+15
	.byte W03
	.byte VOL, 42
	.byte BEND, c_v+6
	.byte VOL, 42
	.byte W03
	.byte BEND, c_v-2
	.byte VOL, 19
	.byte W03
	.byte BEND, c_v-11
	.byte VOL, 8
	.byte W03
	.byte BEND, c_v-19
	.byte VOL, 3
	.byte W03
	.byte FINE

.align 2

track_445:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6d54
	.word track_445_0

.align 2
