.align 2

.global track_111

track_111_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 75
	.byte PAN, c_v
	.byte N06, Cn3, v116
	.byte W06
	.byte N05, Cn3, v052
	.byte W05
	.byte N04, Cn3, v028
	.byte W05
	.byte FINE

track_111_1:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 75
	.byte PAN, c_v
	.byte MOD, 110
	.byte LFOS, 127
	.byte N02, As4, v080
	.byte W05
	.byte LFOS, 0
	.byte W01
	.byte 127 @ LFOS
	.byte N02 @ As4, v080
	.byte W04
	.byte LFOS, 0
	.byte W01
	.byte 127 @ LFOS
	.byte N02 @ As4, v080
	.byte W05
	.byte FINE

.align 2

track_111:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_111_0
	.word track_111_1

.align 2
