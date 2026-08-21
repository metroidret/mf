.align 2

.global track_390

track_390_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 44
	.byte PAN, c_v
	.byte N02, Bn1, v060
	.byte W02
	.byte Cn2, v080 @ N02
	.byte W02
	.byte En2, v100 @ N02
	.byte W02
	.byte VOICE, 69
	.byte VOL, 70
	.byte N15, Cn3, v127
	.byte W90
	.byte W03
	.byte FINE

.align 2

track_390:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_390_0

.align 2
