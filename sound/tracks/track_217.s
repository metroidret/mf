.align 2

.global track_217

track_217_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 127
	.byte PAN, c_v
	.byte N19, Cn3, v127
	.byte W19
	.byte Cn3, v080 @ N19
	.byte W19
	.byte Cn3, v040 @ N19
	.byte W36
	.byte FINE

track_217_1:
	.byte KEYSH, 0
	.byte VOICE, 30
	.byte VOL, 55
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N03, Cn3, v100
	.byte W03
	.byte N02, Cn3, v044
	.byte W02
	.byte VOICE, 6
	.byte VOL, 127
	.byte N06, Cn3, v112
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v080 @ N14
	.byte W14
	.byte VOICE, 10
	.byte N01, Cs2, v127
	.byte W32
	.byte W03
	.byte FINE

.align 2

track_217:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_217_0
	.word track_217_1

.align 2
