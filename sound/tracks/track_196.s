.align 2

.global track_196

track_196_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte MOD, 20
	.byte VOL, 31
	.byte PAN, c_v
	.byte LFOS, 10
	.byte N72, Cn3, v100
	.byte W96
	.byte FINE

track_196_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte MOD, 60
	.byte VOL, 31
	.byte PAN, c_v
	.byte LFOS, 127
	.byte W36
	.byte N24, Cn3, v060
	.byte W60
	.byte FINE

.align 2

track_196:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word 0x80a74c8
	.word track_196_0
	.word track_196_1

.align 2
