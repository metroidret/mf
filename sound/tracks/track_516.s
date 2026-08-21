.align 2

.global track_516

track_516_0:
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
	.byte W24
	.byte W01
	.byte FINE

track_516_1:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 73
	.byte VOL, 127
	.byte W06
	.byte N02, Ds5, v032
	.byte W02
	.byte As5, v016 @ N02
	.byte W02
	.byte As5, v032 @ N02
	.byte W02
	.byte Fn6, v016 @ N02
	.byte W02
	.byte Gs5, v032 @ N02
	.byte W02
	.byte Ds6, v016 @ N02
	.byte W02
	.byte Ds5, v032 @ N02
	.byte W02
	.byte As5, v016 @ N02
	.byte W02
	.byte Gs5, v032 @ N02
	.byte W02
	.byte Ds6, v016 @ N02
	.byte W02
	.byte Ds6, v032 @ N02
	.byte W02
	.byte As6, v016 @ N02
	.byte W02
	.byte Fn6, v032 @ N02
	.byte W02
	.byte Cn7, v016 @ N02
	.byte W02
	.byte FINE

track_516_2:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 60
	.byte VOL, 24
	.byte BEND, c_v+6
	.byte N02, Ds2, v048
	.byte W02
	.byte As2, v036 @ N02
	.byte W02
	.byte As2, v048 @ N02
	.byte W02
	.byte Fn3, v036 @ N02
	.byte W02
	.byte Gs2, v048 @ N02
	.byte W02
	.byte Ds3, v036 @ N02
	.byte W02
	.byte Ds2, v048 @ N02
	.byte W02
	.byte As2, v036 @ N02
	.byte W02
	.byte Gs2, v048 @ N02
	.byte W02
	.byte Ds3, v036 @ N02
	.byte W02
	.byte Ds3, v048 @ N02
	.byte W02
	.byte As3, v036 @ N02
	.byte W02
	.byte Fn3, v048 @ N02
	.byte W02
	.byte Cn4, v036 @ N02
	.byte W08
	.byte FINE

.align 2

track_516:
	.byte 3
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_516_0
	.word track_516_1
	.word track_516_2

.align 2
