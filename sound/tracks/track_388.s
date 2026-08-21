.align 2

.global track_388

track_388_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 66
	.byte VOL, 60
	.byte PAN, c_v
	.byte N72, An1, v127
	.byte W88
	.byte W01
	.byte FINE

track_388_1:
	.byte KEYSH, 0
	.byte VOICE, 67
	.byte MOD, 0
	.byte VOL, 85
	.byte LFOS, 0
	.byte N36, An2, v080
	.byte W88
	.byte W01
	.byte FINE

.align 2

track_388:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6d54
	.word track_388_0
	.word track_388_1

.align 2
