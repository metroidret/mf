.align 2

.global track_170

track_170_0:
	.byte KEYSH, 0
	.byte TEMPO, 80
	.byte VOICE, 3
	.byte VOL, 82
	.byte PRIO, 110
	.byte N04, En4, v112
	.byte W08
	.byte N04 @ En4, v112
	.byte W08
	.byte N07, Fn4 @ v112
	.byte W32
	.byte FINE

track_170_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 82
	.byte PRIO, 109
	.byte N04, Bn2, v112
	.byte W08
	.byte N04 @ Bn2, v112
	.byte W08
	.byte N07, Cn3 @ v112
	.byte W32
	.byte FINE

track_170_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 105
	.byte PRIO, 108
	.byte N04, Bn0, v127
	.byte W08
	.byte N04 @ Bn0, v127
	.byte W08
	.byte N07, Cn1 @ v127
	.byte W32
	.byte FINE

track_170_3:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 82
	.byte PRIO, 30
	.byte N04, Fn2, v112
	.byte W08
	.byte N04 @ Fn2, v112
	.byte W08
	.byte N07, Fs2 @ v112
	.byte W32
	.byte FINE

track_170_4:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 82
	.byte PRIO, 29
	.byte N06, Dn1, v112
	.byte W08
	.byte N06 @ Dn1, v112
	.byte W08
	.byte N16 @ Dn1, v112
	.byte W32
	.byte FINE

track_170_5:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 82
	.byte PRIO, 28
	.byte N04, Fn3, v112
	.byte W08
	.byte N04 @ Fn3, v112
	.byte W08
	.byte N07, Fs3 @ v112
	.byte W32
	.byte FINE

track_170_6:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 105
	.byte PRIO, 30
	.byte N06, Bn1, v127
	.byte W08
	.byte N06 @ Bn1, v127
	.byte W08
	.byte N08, Cn2 @ v127
	.byte W32
	.byte FINE

.align 2

track_170:
	.byte 7
	.byte 0
	.byte 130
	.byte 128
	.word 0x80a64c0
	.word track_170_0
	.word track_170_1
	.word track_170_2
	.word track_170_3
	.word track_170_4
	.word track_170_5
	.word track_170_6

.align 2
