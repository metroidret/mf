.align 2

.global track_192

track_192_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 49
	.byte PAN, c_v
	.byte N24, Cn3, v127
	.byte W48
	.byte FINE

track_192_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 33
	.byte PAN, c_v
	.byte N05, Fn3, v080
	.byte W05
	.byte As3 @ N05, v080
	.byte W05
	.byte Fs3 @ N05, v080
	.byte W05
	.byte VOICE, 24
	.byte N05, Fn3, v040
	.byte W05
	.byte As3, v052 @ N05
	.byte W05
	.byte Fs3, v060 @ N05
	.byte W05
	.byte En3, v052 @ N05
	.byte W05
	.byte N06, As3, v072
	.byte W13
	.byte FINE

.align 2

track_192:
	.byte 2
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a74c8
	.word track_192_0
	.word track_192_1

.align 2
