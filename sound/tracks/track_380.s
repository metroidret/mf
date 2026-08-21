.align 2

.global track_380

track_380_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 40
	.byte PAN, c_v
	.byte W08
	.byte N06, Cn2, v100
	.byte W06
	.byte N03, Fn2, v080
	.byte W03
	.byte Fn2, v060 @ N03
	.byte W10
	.byte Gn2 @ N03, v060
	.byte W03
	.byte Bn2 @ N03, v060
	.byte W03
	.byte FINE

.align 2

track_380:
	.byte 1
	.byte 0
	.byte 140
	.byte 0
	.word 0x80a6d54
	.word track_380_0

.align 2
