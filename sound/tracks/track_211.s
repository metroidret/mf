.align 2

.global track_211

track_211_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 115
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 9
	.byte N10, Cn3, v040
	.byte W24
	.byte W02
	.byte FINE

track_211_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 115
	.byte PAN, c_v
	.byte W05
	.byte N09, Fn3, v100
	.byte W09
	.byte VOICE, 10
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
	.byte N03, Cs2, v127
	.byte W32
	.byte W03
	.byte FINE

.align 2

track_211:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_211_0
	.word track_211_1

.align 2
