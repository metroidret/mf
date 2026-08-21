.align 2

.global track_183

track_183_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 127
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W04
	.byte N08, Fn3 @ v127
	.byte W08
	.byte Cn3 @ N08, v127
	.byte W12
	.byte Cn3, v100 @ N08
	.byte W10
	.byte Cn3, v052 @ N08
	.byte W08
	.byte Cn3, v020 @ N08
	.byte W12
	.byte FINE

track_183_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 127
	.byte PAN, c_v
	.byte W01
	.byte N03, Cn2, v080
	.byte W03
	.byte VOICE, 8
	.byte VOL, 60
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 9
	.byte N02, Cn5, v080
	.byte W02
	.byte VOICE, 8
	.byte N08, Fn3, v127
	.byte W08
	.byte Cn3 @ N08, v127
	.byte W08
	.byte VOICE, 9
	.byte N04, Cn5, v080
	.byte W04
	.byte VOICE, 8
	.byte N08, Cn3, v100
	.byte W10
	.byte Cn3, v052 @ N08
	.byte W08
	.byte Cn3, v020 @ N08
	.byte W08
	.byte FINE

.align 2

track_183:
	.byte 2
	.byte 0
	.byte 182
	.byte 0
	.word 0x80a74c8
	.word track_183_0
	.word track_183_1

.align 2
