.align 2

.global track_401

track_401_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 70
	.byte VOL, 0
	.byte PAN, c_v
	.byte W13
	.byte MOD, 40
	.byte VOL, 12
	.byte BENDR, 10
	.byte LFOS, 40
	.byte BEND, c_v-49
	.byte N48, Gs2, v127
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 20
	.byte BEND, c_v-36
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 28
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v-11
	.byte W02
	.byte VOL, 31
	.byte W02
	.byte 25 @ VOL
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 21
	.byte W02
	.byte 17 @ VOL
	.byte BEND, c_v-11
	.byte W02
	.byte VOL, 14
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte 4 @ VOL
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 3
	.byte W02
	.byte 2 @ VOL
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 0
	.byte W01
	.byte 0 @ VOL
	.byte BEND, c_v-19
	.byte W01
	.byte FINE

.align 2

track_401:
	.byte 1
	.byte 0
	.byte 141
	.byte 0
	.word 0x80a6d54
	.word track_401_0

.align 2
