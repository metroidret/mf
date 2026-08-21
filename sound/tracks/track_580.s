.align 2

.global track_580

track_580_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte W48
	.byte VOL, 127
	.byte N36, Bn3, v024
	.byte W24
	.byte VOL, 64
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W12
track_580_lbl_278ff4:
	.byte W12
	.byte VOL, 127
	.byte N36, Bn3, v024
	.byte W24
	.byte VOL, 64
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W24
	.byte 127 @ VOL
	.byte N36 @ Bn3, v024
	.byte W24
	.byte VOL, 64
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W12
	.byte GOTO
		.word track_580_lbl_278ff4
	.byte FINE

track_580_1:
	.byte KEYSH, 0
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
track_580_lbl_27906e:
	.byte W96
	.byte W24
	.byte GOTO
		.word track_580_lbl_27906e
	.byte FINE

track_580_2:
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
track_580_lbl_2790ab:
	.byte W96
	.byte W24
	.byte GOTO
		.word track_580_lbl_2790ab
	.byte FINE

.align 2

track_580:
	.byte 3
	.byte 0
	.byte 254
	.byte 128
	.word 0x80a8554
	.word track_580_0
	.word track_580_1
	.word track_580_2

.align 2
