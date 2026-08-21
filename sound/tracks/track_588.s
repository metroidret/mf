.align 2

.global track_588

track_588_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W03
	.byte VOICE, 73
	.byte VOL, 127
	.byte W06
	.byte N02, Bn4, v032
	.byte W02
	.byte Fs5, v016 @ N02
	.byte W02
	.byte Fs5, v032 @ N02
	.byte W02
	.byte Cs6, v016 @ N02
	.byte W02
	.byte En5, v032 @ N02
	.byte W02
	.byte Bn5, v016 @ N02
	.byte W02
	.byte Bn5, v032 @ N02
	.byte W02
	.byte Fs6, v016 @ N02
	.byte W02
	.byte An5, v032 @ N02
	.byte W02
	.byte En6, v016 @ N02
	.byte W02
	.byte En6, v032 @ N02
	.byte W02
	.byte Bn6, v016 @ N02
	.byte W02
	.byte Fs6, v032 @ N02
	.byte W02
	.byte Cs7, v016 @ N02
	.byte W60
	.byte W01
track_588_lbl_27b79a:
	.byte W96
	.byte W24
	.byte GOTO
		.word track_588_lbl_27b79a
	.byte FINE

track_588_1:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 60
	.byte VOL, 24
	.byte BEND, c_v+6
	.byte N02, Bn1, v048
	.byte W02
	.byte Fs2, v036 @ N02
	.byte W02
	.byte Fs2, v048 @ N02
	.byte W02
	.byte Cs3, v036 @ N02
	.byte W02
	.byte En2, v048 @ N02
	.byte W02
	.byte Bn2, v036 @ N02
	.byte W02
	.byte Bn2, v048 @ N02
	.byte W02
	.byte Fs3, v036 @ N02
	.byte W02
	.byte An2, v048 @ N02
	.byte W02
	.byte En3, v036 @ N02
	.byte W02
	.byte En3, v048 @ N02
	.byte W02
	.byte Bn3, v036 @ N02
	.byte W02
	.byte Fs3, v048 @ N02
	.byte W02
	.byte Cs4, v036 @ N02
	.byte W66
	.byte W01
track_588_lbl_27b7d7:
	.byte W96
	.byte W24
	.byte GOTO
		.word track_588_lbl_27b7d7
	.byte FINE

.align 2

track_588:
	.byte 2
	.byte 0
	.byte 254
	.byte 128
	.word 0x80a8554
	.word track_588_0
	.word track_588_1

.align 2
