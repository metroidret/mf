.align 2

.global track_264

track_264_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W07
	.byte N02, Bn1, v040
	.byte W02
	.byte Bn2 @ N02, v040
	.byte W06
	.byte Fn2, v044 @ N02
	.byte W02
	.byte Cn3 @ N02, v044
	.byte W07
	.byte VOICE, 15
	.byte N04, Cn3, v080
	.byte W04
	.byte VOICE, 9
	.byte N11, Fn3, v127
	.byte W42
	.byte W01
	.byte FINE

track_264_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 44
	.byte PAN, c_v
	.byte W05
	.byte N05, An2, v080
	.byte W08
	.byte Bn2 @ N05, v080
	.byte W11
	.byte VOICE, 11
	.byte VOL, 13
	.byte W04
	.byte N18, Cn3, v127
	.byte W42
	.byte W01
	.byte FINE

.align 2

track_264:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_264_0
	.word track_264_1

.align 2
