.align 2

.global track_687

track_687_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 79
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte W01
	.byte N28, Bn2, v100
	.byte W19
	.byte BEND, c_v+9
	.byte W28
	.byte FINE

track_687_1:
	.byte KEYSH, 0
	.byte VOICE, 86
	.byte VOL, 127
	.byte PAN, c_v
	.byte N12, Gn3, v127
	.byte W12
	.byte Gn3, v060 @ N12
	.byte W12
	.byte Gn3, v020 @ N12
	.byte W24
	.byte FINE

.align 2

track_687:
	.byte 2
	.byte 0
	.byte 255
	.byte 0
	.word 0x80a6d54
	.word track_687_0
	.word track_687_1

.align 2
