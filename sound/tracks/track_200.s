.align 2

.global track_200

track_200_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 65
	.byte PAN, c_v
	.byte N05, Cn3, v040
	.byte W05
	.byte VOICE, 16
	.byte N06, Cn3, v080
	.byte W06
	.byte VOICE, 17
	.byte N06 @ Cn3, v080
	.byte W06
	.byte VOICE, 18
	.byte VOL, 65
	.byte N15 @ Cn3, v080
	.byte W02
	.byte VOL, 54
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_200:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_200_0

.align 2
