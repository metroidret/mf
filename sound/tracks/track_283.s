.align 2

.global track_283

track_283_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 47
	.byte PAN, c_v
	.byte N06, Ds3, v120
	.byte W06
	.byte Ds3, v060 @ N06
	.byte W06
	.byte Ds3, v040 @ N06
	.byte W06
	.byte Ds3, v028 @ N06
	.byte W06
	.byte Ds3, v020 @ N06
	.byte W06
	.byte Ds3, v012 @ N06
	.byte W06
	.byte Ds3, v008 @ N06
	.byte W06
	.byte Ds3, v004 @ N06
	.byte W54
	.byte Ds3, v100 @ N06
	.byte W06
	.byte Ds3, v060 @ N06
	.byte W06
	.byte Ds3, v040 @ N06
	.byte W06
	.byte Ds3, v028 @ N06
	.byte W06
	.byte Ds3, v020 @ N06
	.byte W06
	.byte Ds3, v012 @ N06
	.byte W06
	.byte Ds3, v008 @ N06
	.byte W06
	.byte Ds3, v004 @ N06
	.byte W06
	.byte FINE

.align 2

track_283:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a71ec
	.word track_283_0

.align 2
