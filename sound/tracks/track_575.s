.align 2

.global track_575

track_575_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 75
	.byte PAN, c_v
	.byte N44, Cn3, v127
	.byte W96
	.byte FINE

track_575_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 75
	.byte PAN, c_v
	.byte W05
	.byte N09, Fn2, v100
	.byte W09
	.byte VOICE, 44
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
	.byte N03, Ds2, v127
	.byte W68
	.byte W03
	.byte FINE

.align 2

track_575:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_575_0
	.word track_575_1

.align 2
