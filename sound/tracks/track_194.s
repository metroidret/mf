.align 2

.global track_194

track_194_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 70
	.byte PAN, c_v
	.byte N36, Gs2, v127
	.byte W36
	.byte FINE

track_194_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 127
	.byte PAN, c_v
	.byte N30, Cn3, v127
	.byte W36
	.byte FINE

.align 2

track_194:
	.byte 2
	.byte 0
	.byte 230
	.byte 0
	.word 0x80a74c8
	.word track_194_0
	.word track_194_1

.align 2
