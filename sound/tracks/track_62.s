.align 2

.global track_62

track_62_0:
	.byte KEYSH, 0
	.byte TEMPO, 30
	.byte VOICE, 5
	.byte VOL, 70
	.byte PRIO, 110
	.byte W72
	.byte W02
	.byte N10, Cn2, v048
	.byte W10
	.byte N08, Cs2, v064
	.byte W08
	.byte N07, Fn2, v068
	.byte W07
	.byte An2, v056 @ N07
	.byte W07
	.byte N06, Cn3 @ v056
	.byte W06
	.byte N07, Cs3, v068
	.byte W07
	.byte N06, Fn3 @ v068
	.byte W06
	.byte N07, An3, v080
	.byte W07
	.byte Cn4, v064 @ N07
	.byte W07
	.byte Cs4, v052 @ N07
	.byte W05
	.byte W02
	.byte Fn4 @ N07, v052
	.byte W07
	.byte An4 @ N07, v052
	.byte W07
	.byte N08, Cn5, v064
	.byte W08
	.byte Cs5, v036 @ N08
	.byte W08
	.byte Fn5 @ N08, v036
	.byte W08
	.byte An5, v024 @ N08
	.byte W32
	.byte W72
track_62_lbl_269ab1:
	.byte VOL, 49
	.byte N08, Fn3, v060
	.byte W08
	.byte An3, v052 @ N08
	.byte W08
	.byte Cn4, v064 @ N08
	.byte W08
	.byte Cs4, v036 @ N08
	.byte W08
	.byte Fn4 @ N08, v036
	.byte W08
	.byte An4, v024 @ N08
	.byte W08
	.byte Fn3, v060 @ N08
	.byte W08
	.byte An3, v052 @ N08
	.byte W08
	.byte Cn4, v064 @ N08
	.byte W08
track_62_lbl_269ace:
	.byte N08, Cs4, v036
	.byte W08
	.byte En4 @ N08, v036
	.byte W08
	.byte Gs4, v024 @ N08
	.byte W56
	.byte PEND
	.byte Fn3, v060 @ N08
	.byte W08
	.byte An3, v052 @ N08
	.byte W08
	.byte Cn4, v064 @ N08
	.byte W08
	.byte Cs4, v036 @ N08
	.byte W08
	.byte Fn4 @ N08, v036
	.byte W08
	.byte An4, v024 @ N08
	.byte W08
	.byte Fn3, v060 @ N08
	.byte W08
	.byte An3, v052 @ N08
	.byte W08
	.byte Cn4, v064 @ N08
	.byte W08
	.byte PATT
		.word track_62_lbl_269ace
	.byte GOTO
		.word track_62_lbl_269ab1
	.byte FINE

track_62_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte PRIO, 109
	.byte W72
	.byte 6 @ VOICE
	.byte VOL, 53
	.byte TIE, Fn2, v072
	.byte W02
	.byte VOL, 55
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W42
	.byte W01
	.byte W72
	.byte W02
	.byte 69 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Fn2, v072
track_62_lbl_269bb2:
	.byte VOL, 0
	.byte W05
	.byte VOICE, 5
	.byte VOL, 70
	.byte N08, Fn3, v032
	.byte W08
	.byte An3, v028 @ N08
	.byte W08
	.byte Cn4, v036 @ N08
	.byte W08
	.byte Cs4, v016 @ N08
	.byte W08
	.byte Fn4 @ N08, v016
	.byte W08
	.byte An4, v008 @ N08
	.byte W08
	.byte Fn3, v032 @ N08
	.byte W08
	.byte An3, v028 @ N08
	.byte W08
	.byte Cn4, v036 @ N08
	.byte W03
track_62_lbl_269bd4:
	.byte W05
	.byte N08, Cs4, v016
	.byte W08
	.byte En4 @ N08, v016
	.byte W08
	.byte Gs4, v008 @ N08
	.byte W48
	.byte W03
	.byte PEND
	.byte W05
	.byte Fn3, v032 @ N08
	.byte W08
	.byte An3, v028 @ N08
	.byte W08
	.byte Cn4, v036 @ N08
	.byte W08
	.byte Cs4, v016 @ N08
	.byte W08
	.byte Fn4 @ N08, v016
	.byte W08
	.byte An4, v008 @ N08
	.byte W08
	.byte Fn3, v032 @ N08
	.byte W08
	.byte An3, v028 @ N08
	.byte W08
	.byte Cn4, v036 @ N08
	.byte W03
	.byte PATT
		.word track_62_lbl_269bd4
	.byte GOTO
		.word track_62_lbl_269bb2
	.byte FINE

track_62_2:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 14
	.byte PRIO, 108
	.byte N24, Cs4, v064
	.byte W24
	.byte VOL, 7
	.byte N72, Gs4 @ v064
	.byte W06
	.byte VOL, 8
	.byte W05
	.byte 9 @ VOL
	.byte W05
	.byte 11 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte W24
	.byte TIE, An4 @ v064
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W07
	.byte 14 @ VOL
	.byte W19
	.byte W04
	.byte 12 @ VOL
	.byte W24
	.byte W03
	.byte 11 @ VOL
	.byte W24
	.byte W03
	.byte 9 @ VOL
	.byte W14
	.byte EOT @ An4, v064
	.byte W72
track_62_lbl_269c60:
	.byte W48
	.byte VOICE, 6
	.byte VOL, 7
	.byte N96, Fn2, v072
	.byte W02
	.byte VOL, 9
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte PEND
track_62_lbl_269c89:
	.byte W01
	.byte VOL, 34
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W02
	.byte PEND
	.byte PATT
		.word track_62_lbl_269c60
	.byte PATT
		.word track_62_lbl_269c89
	.byte GOTO
		.word track_62_lbl_269c60
	.byte FINE

track_62_3:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 8
	.byte PRIO, 30
	.byte TIE, Fn3, v064
	.byte W12
	.byte VOL, 7
	.byte W17
	.byte 8 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W07
	.byte 14 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte W24
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W06
	.byte 21 @ VOL
	.byte W12
	.byte 19 @ VOL
	.byte W08
	.byte 18 @ VOL
	.byte W01
	.byte W09
	.byte 17 @ VOL
	.byte W10
	.byte 15 @ VOL
	.byte W11
	.byte 14 @ VOL
	.byte W18
	.byte EOT @ Fn3, v064
	.byte W24
	.byte W72
track_62_lbl_269d33:
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte GOTO
		.word track_62_lbl_269d33
	.byte FINE

.align 2

track_62:
	.byte 4
	.byte 62
	.byte 130
	.byte 128
	.word 0x80a5cf8
	.word track_62_0
	.word track_62_1
	.word track_62_2
	.word track_62_3

.align 2
