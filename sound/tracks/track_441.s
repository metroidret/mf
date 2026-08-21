.align 2

.global track_441

track_441_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 92
	.byte VOL, 21
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v
	.byte N48, Cn3, v080
	.byte W03
	.byte VOL, 25
	.byte BEND, c_v-5
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 32
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-21
	.byte W03
	.byte VOL, 30
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 26
	.byte W01
	.byte BEND, c_v-33
	.byte W02
	.byte VOL, 18
	.byte W01
	.byte BEND, c_v-37
	.byte W02
	.byte VOL, 11
	.byte W01
	.byte BEND, c_v-41
	.byte W02
	.byte VOL, 7
	.byte W01
	.byte BEND, c_v-45
	.byte W02
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v-49
	.byte W02
	.byte VOL, 2
	.byte W01
	.byte BEND, c_v-53
	.byte W02
	.byte VOL, 1
	.byte W01
	.byte BEND, c_v-57
	.byte W02
	.byte VOL, 0
	.byte W01
	.byte BEND, c_v-61
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W01
	.byte FINE

.align 2

track_441:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a6d54
	.word track_441_0

.align 2
