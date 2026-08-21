.align 2

.global track_22

track_22_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 86
	.byte N96, Cn4, v100
	.byte W96
	.byte Dn4 @ N96, v100
	.byte W96
	.byte En4 @ N96, v100
	.byte W96
	.byte 0xB6

.align 2

track_22:
	.byte 1
	.byte 22
	.byte 130
	.byte 128
	.word 0x80a62f8
	.word track_22_0

.align 2
