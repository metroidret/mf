.align 2

.global track_267

track_267_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 36
	.byte PAN, c_v
	.byte N16, Fn2, v127
	.byte W02
	.byte VOL, 44
	.byte W02
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_267_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 41
	.byte PAN, c_v
	.byte N16, Cn3, v080
	.byte W16
	.byte FINE

.align 2

track_267:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_267_0
	.word track_267_1

.align 2
