.align 2

.global track_202

track_202_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 75
	.byte PAN, c_v
	.byte N05, Cn3, v040
	.byte W05
	.byte VOICE, 21
	.byte N06, Cn3, v100
	.byte W06
	.byte VOICE, 17
	.byte N06, Cn3, v080
	.byte W06
	.byte VOICE, 18
	.byte N15 @ Cn3, v080
	.byte W02
	.byte VOL, 62
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_202:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_202_0

.align 2
