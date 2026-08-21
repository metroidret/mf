.align 2

.global track_322

track_322_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 45
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 2
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 3
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 4
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 5
	.byte N05, Cn3, v032
	.byte W05
	.byte VOICE, 9
	.byte N05, Cn3, v012
	.byte W05
	.byte VOICE, 4
	.byte N05, Cn3, v020
	.byte W05
	.byte VOICE, 7
	.byte N05, Cn3, v032
	.byte W05
	.byte VOICE, 2
	.byte N05, Cn3, v020
	.byte W05
	.byte VOICE, 8
	.byte N05, Cn3, v012
	.byte W05
	.byte VOICE, 6
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 7
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 8
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 9
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 10
	.byte N05 @ Cn3, v127
	.byte W05
	.byte FINE

.align 2

track_322:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word 0x80a6d54
	.word track_322_0

.align 2
