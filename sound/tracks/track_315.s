.align 2

.global track_315

track_315_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 127
	.byte PAN, c_v
	.byte N06, Cn3, v116
	.byte W06
	.byte N05, Cn3, v052
	.byte W05
	.byte N04, Cn3, v028
	.byte W05
	.byte FINE

track_315_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte MOD, 110
	.byte VOL, 127
	.byte PAN, c_v
	.byte LFOS, 127
	.byte PRIO, 40
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

track_315:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a82f0
	.word track_315_0
	.word track_315_1

.align 2
