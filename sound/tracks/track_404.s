.align 2

.global track_404

track_404_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 10
	.byte BEND, c_v
	.byte N20, Cn2, v100
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 53
	.byte W03
	.byte 50 @ VOL
	.byte BEND, c_v-3
	.byte W03
	.byte VOL, 46
	.byte W02
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 40
	.byte W03
	.byte 31 @ VOL
	.byte BEND, c_v-19
	.byte W03
	.byte VOL, 11
	.byte W01
	.byte 0 @ VOL
	.byte BEND, c_v-31
	.byte W01
	.byte FINE

.align 2

track_404:
	.byte 1
	.byte 0
	.byte 167
	.byte 0
	.word 0x80a6d54
	.word track_404_0

.align 2
