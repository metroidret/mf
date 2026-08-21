.align 2

.global track_517

track_517_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 75
	.byte VOL, 127
	.byte BEND, c_v
	.byte N06, As3, v072
	.byte W06
	.byte As3, v020 @ N06
	.byte W06
	.byte As3, v012 @ N06
	.byte W09
	.byte FINE

track_517_1:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 73
	.byte VOL, 127
	.byte W06
	.byte N02, An5, v032
	.byte W02
	.byte En6, v016 @ N02
	.byte W02
	.byte Dn5, v032 @ N02
	.byte W02
	.byte An5, v016 @ N02
	.byte W02
	.byte En5, v032 @ N02
	.byte W02
	.byte Bn5, v016 @ N02
	.byte W02
	.byte FINE

track_517_2:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 60
	.byte VOL, 24
	.byte BEND, c_v+6
	.byte N02, An2, v048
	.byte W02
	.byte En3, v036 @ N02
	.byte W02
	.byte Dn2, v048 @ N02
	.byte W02
	.byte An2, v036 @ N02
	.byte W02
	.byte En2, v048 @ N02
	.byte W02
	.byte Bn2, v036 @ N02
	.byte W08
	.byte FINE

.align 2

track_517:
	.byte 3
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_517_0
	.word track_517_1
	.word track_517_2

.align 2
