.align 2

.global track_263

track_263_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 25
	.byte PAN, c_v
	.byte N10, Cn3, v127
	.byte W10
	.byte N05, Cn3, v060
	.byte W05
	.byte Cn3, v032 @ N05
	.byte W19
	.byte FINE

track_263_1:
	.byte KEYSH, 0
	.byte VOICE, 44
	.byte VOL, 27
	.byte PAN, c_v
	.byte N04, Cn3, v080
	.byte W05
	.byte Cn3, v127 @ N04
	.byte W05
	.byte Cn3, v100 @ N04
	.byte W04
	.byte VOICE, 45
	.byte N04, Cn3, v080
	.byte W04
	.byte VOICE, 46
	.byte N04, Cn3, v040
	.byte W16
	.byte FINE

track_263_2:
	.byte KEYSH, 0
	.byte VOICE, 47
	.byte VOL, 50
	.byte PAN, c_v
	.byte N15, Fs2, v127
	.byte W32
	.byte W02
	.byte FINE

.align 2

track_263:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_263_0
	.word track_263_1
	.word track_263_2

.align 2
