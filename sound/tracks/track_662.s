.align 2

.global track_662

track_662_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 37
	.byte PAN, c_v
	.byte W03
	.byte N22, Cn2, v127
	.byte W24
	.byte W02
	.byte FINE

track_662_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 23
	.byte PAN, c_v
	.byte W20
	.byte N05, Fn4, v100
	.byte W09
	.byte FINE

.align 2

track_662:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a7f24
	.word track_662_0
	.word track_662_1

.align 2
