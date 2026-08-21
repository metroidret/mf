.align 2

.global track_346

track_346_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 53
	.byte VOL, 57
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v-33
	.byte N44, Bn2, v080
	.byte W03
	.byte VOL, 65
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 75
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 82
	.byte W01
	.byte BEND, c_v-6
	.byte W02
	.byte VOL, 83
	.byte W01
	.byte BEND, c_v
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 86
	.byte W01
	.byte BEND, c_v+9
	.byte VOL, 87
	.byte W01
	.byte 76 @ VOL
	.byte W02
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 41
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 10
	.byte W03
	.byte 6 @ VOL
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 3
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 0
	.byte W24
	.byte FINE

track_346_1:
	.byte KEYSH, 0
	.byte VOICE, 52
	.byte VOL, 90
	.byte PAN, c_v
	.byte N05, Cn3, v100
	.byte W03
	.byte VOL, 49
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte VOICE, 54
	.byte VOL, 56
	.byte N15, As2 @ v100
	.byte W15
	.byte N14, Fs2 @ v100
	.byte W24
	.byte W01
	.byte VOL, 28
	.byte W03
	.byte 14 @ VOL
	.byte W20
	.byte FINE

.align 2

track_346:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6d54
	.word track_346_0
	.word track_346_1

.align 2
