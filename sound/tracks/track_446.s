.align 2

.global track_446

track_446_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 66
	.byte PAN, c_v
	.byte N36, Gs2, v127
	.byte W36
	.byte N14, Cn3, v064
	.byte W14
	.byte FINE

track_446_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 120
	.byte PAN, c_v
	.byte N30, Gn2, v080
	.byte W48
	.byte W02
	.byte FINE

track_446_2:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 120
	.byte PAN, c_v
	.byte W20
	.byte N30, Cn3, v127
	.byte W30
	.byte FINE

.align 2

track_446:
	.byte 3
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a74c8
	.word track_446_0
	.word track_446_1
	.word track_446_2

.align 2
