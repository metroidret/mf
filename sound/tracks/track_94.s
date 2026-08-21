.align 2

.global track_94

track_94_0:
	.byte KEYSH, 0
track_94_lbl_26f03e:
	.byte TEMPO, 60
	.byte VOICE, 3
	.byte VOL, 28
	.byte N03, An3, v096
	.byte W18
	.byte An3, v052 @ N03
	.byte W18
	.byte An3, v032 @ N03
	.byte W24
	.byte An3, v040 @ N03
	.byte W12
	.byte N04, As3, v060
	.byte W06
	.byte As3, v048 @ N04
	.byte W18
	.byte An3, v072 @ N04
	.byte W18
	.byte An3, v036 @ N04
	.byte W18
	.byte An3, v080 @ N04
	.byte W24
	.byte An3, v120 @ N04
	.byte W12
	.byte As3 @ N04, v120
	.byte W06
	.byte N04 @ As3, v120
	.byte W18
	.byte GOTO
		.word track_94_lbl_26f03e
	.byte FINE

track_94_1:
	.byte KEYSH, 0
track_94_lbl_26f070:
	.byte VOICE, 3
	.byte VOL, 28
	.byte N03, Gs3, v096
	.byte W18
	.byte Gs3, v052 @ N03
	.byte W18
	.byte Gs3, v032 @ N03
	.byte W24
	.byte Gs3, v040 @ N03
	.byte W12
	.byte N04, Gs3, v020
	.byte W06
	.byte Gs3, v028 @ N04
	.byte W18
	.byte Gs3, v040 @ N04
	.byte W18
	.byte Gs3, v032 @ N04
	.byte W18
	.byte Gs3, v052 @ N04
	.byte W24
	.byte Gs3, v080 @ N04
	.byte W12
	.byte N04 @ Gs3, v080
	.byte W06
	.byte N04 @ Gs3, v080
	.byte W18
	.byte GOTO
		.word track_94_lbl_26f070
	.byte FINE

track_94_2:
	.byte KEYSH, 0
track_94_lbl_26f0a0:
	.byte VOICE, 0
	.byte VOL, 14
	.byte N04, Fs1, v100
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v080 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v100 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v080 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v100 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v080 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v100 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v092 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte Fs1, v080 @ N04
	.byte W06
	.byte Fs1, v060 @ N04
	.byte W06
	.byte GOTO
		.word track_94_lbl_26f0a0
	.byte FINE

track_94_3:
	.byte KEYSH, 0
track_94_lbl_26f10d:
	.byte VOICE, 6
	.byte VOL, 70
	.byte N12, Cn1, v092
	.byte W84
	.byte N04, Cn2, v100
	.byte W06
	.byte Fs1 @ N04, v100
	.byte W06
	.byte N12, Cn1 @ v100
	.byte W84
	.byte N05, Cn2, v120
	.byte W06
	.byte N06, Cn2, v112
	.byte W06
	.byte GOTO
		.word track_94_lbl_26f10d
	.byte FINE

.align 2

track_94:
	.byte 4
	.byte 94
	.byte 130
	.byte 128
	.word 0x80a64c0
	.word track_94_0
	.word track_94_1
	.word track_94_2
	.word track_94_3

.align 2
