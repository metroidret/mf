.align 2

.global track_208

track_208_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N19, Cn3, v127
	.byte W19
	.byte Cn3, v036 @ N19
	.byte W19
	.byte Cn3, v012 @ N19
	.byte W19
	.byte FINE

track_208_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 100
	.byte PAN, c_v
	.byte N04, As4, v127
	.byte W10
	.byte VOICE, 10
	.byte N05, Gs2, v080
	.byte W10
	.byte N03, Cs2, v127
	.byte W36
	.byte W01
	.byte FINE

.align 2

track_208:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_208_0
	.word track_208_1

.align 2
