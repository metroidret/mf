.align 2

.global track_222

track_222_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 127
	.byte PAN, c_v
	.byte N19, Cn3, v127
	.byte W40
	.byte FINE

track_222_1:
	.byte KEYSH, 0
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte PAN, c_v
	.byte W06
	.byte VOICE, 10
	.byte N14, Gs2, v080
	.byte W32
	.byte FINE

.align 2

track_222:
	.byte 2
	.byte 0
	.byte 185
	.byte 0
	.word 0x80a6af0
	.word track_222_0
	.word track_222_1

.align 2
