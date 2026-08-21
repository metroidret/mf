.align 2

.global track_408

track_408_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 25
	.byte PAN, c_v
	.byte N02, Cn4, v080
	.byte W03
	.byte En4, v072 @ N02
	.byte W03
	.byte Gn4, v060 @ N02
	.byte W03
	.byte Bn4, v040 @ N02
	.byte W03
	.byte Cn5, v020 @ N02
	.byte W02
	.byte FINE

.align 2

track_408:
	.byte 1
	.byte 0
	.byte 141
	.byte 0
	.word 0x80a6d54
	.word track_408_0

.align 2
