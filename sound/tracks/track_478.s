.align 2

.global track_478

track_478_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 10
	.byte PRIO, 1
	.byte N64, Cn3, v127
	.byte W12
	.byte BEND, c_v-1
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W10
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W44
	.byte W01
	.byte W02
	.byte FINE

track_478_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 80
	.byte PAN, c_v
	.byte N32, An2, v127
	.byte W02
	.byte VOL, 79
	.byte W04
	.byte 77 @ VOL
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte VOICE, 2
	.byte VOL, 127
	.byte BENDR, 10
	.byte N64, Cn3, v020
	.byte W12
	.byte BEND, c_v-1
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W10
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W03
	.byte VOL, 127
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W01
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_478:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a81e8
	.word track_478_0
	.word track_478_1

.align 2
