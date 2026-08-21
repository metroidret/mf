.align 2

.global track_129

track_129_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 60
	.byte PAN, c_v
	.byte N01, As4, v127
	.byte W01
	.byte Gs4, v064 @ N01
	.byte W01
	.byte FINE

.align 2

track_129:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a682c
	.word track_129_0

.align 2
