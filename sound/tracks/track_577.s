.align 2

.global track_577

track_577_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 62
	.byte VOL, 55
	.byte PAN, c_v
	.byte W05
	.byte N32, Cn3, v127
	.byte W66
	.byte W01
	.byte FINE

track_577_1:
	.byte KEYSH, 0
	.byte VOL, 55
	.byte PAN, c_v
	.byte W14
	.byte VOICE, 44
	.byte W01
	.byte N05, Gs2, v127
	.byte W10
	.byte N03, Cs2 @ v127
	.byte W44
	.byte W03
	.byte FINE

.align 2

track_577:
	.byte 2
	.byte 0
	.byte 226
	.byte 0
	.word 0x80a7798
	.word track_577_0
	.word track_577_1

.align 2
