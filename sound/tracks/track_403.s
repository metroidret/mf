.align 2

.global track_403

track_403_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 70
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFODL, 20
	.byte W10
	.byte MOD, 40
	.byte VOL, 9
	.byte BENDR, 12
	.byte LFOS, 40
	.byte BEND, c_v-63
	.byte N60, Gs2, v127
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-53
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v-45
	.byte W03
	.byte VOL, 37
	.byte BEND, c_v-39
	.byte W03
	.byte VOL, 42
	.byte BEND, c_v-34
	.byte W03
	.byte VOL, 47
	.byte W03
	.byte 51 @ VOL
	.byte BEND, c_v-35
	.byte W03
	.byte VOL, 49
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 47
	.byte BEND, c_v-18
	.byte W03
	.byte VOL, 43
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 40
	.byte BEND, c_v-16
	.byte W03
	.byte VOL, 33
	.byte BEND, c_v-15
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 14
	.byte BEND, c_v-10
	.byte W03
	.byte VOL, 8
	.byte BEND, c_v-7
	.byte W03
	.byte VOL, 6
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 4
	.byte BEND, c_v-5
	.byte W03
	.byte VOL, 2
	.byte BEND, c_v-3
	.byte W03
	.byte VOL, 1
	.byte W03
	.byte 0 @ VOL
	.byte BEND, c_v-1
	.byte W03
	.byte VOL, 0
	.byte W02
	.byte FINE

.align 2

track_403:
	.byte 1
	.byte 0
	.byte 142
	.byte 0
	.word 0x80a6d54
	.word track_403_0

.align 2
