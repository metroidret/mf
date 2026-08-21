.align 2

.global track_8

track_8_0:
	.byte KEYSH, 0
track_8_lbl_25b6fe:
	.byte TEMPO, 40
	.byte VOICE, 6
	.byte PAN, c_v+20
	.byte VOL, 44
	.byte PRIO, 110
	.byte N12, En6, v056
	.byte W12
	.byte BEND, c_v-4
	.byte N12, An5, v044
	.byte W12
	.byte BEND, c_v
	.byte N24, En6, v048
	.byte W24
	.byte TEMPO, 35
	.byte Ds6, v040 @ N24
	.byte W24
	.byte TEMPO, 40
	.byte N12, Dn6, v044
	.byte W12
	.byte Gn5, v052 @ N12
	.byte W12
	.byte N24, Dn6, v060
	.byte W24
	.byte Cs6, v056 @ N24
	.byte W24
	.byte N12, En6 @ v056
	.byte W12
	.byte Fs5, v048 @ N12
	.byte W12
	.byte N24, En6, v052
	.byte W24
	.byte TEMPO, 34
	.byte Ds6 @ N24, v052
	.byte W24
	.byte N12, Dn6, v036
	.byte W12
	.byte Gn5, v040 @ N12
	.byte W12
	.byte N24, Dn6, v048
	.byte W24
	.byte TEMPO, 30
	.byte N36, Cs6 @ v048
	.byte W24
	.byte TEMPO, 40
	.byte W72
	.byte BEND, c_v-4
	.byte N12, An5, v060
	.byte W12
	.byte BEND, c_v
	.byte N12, An4, v076
	.byte W12
	.byte TEMPO, 44
	.byte BEND, c_v-4
	.byte N12, An5, v092
	.byte W12
	.byte BEND, c_v
	.byte N12, An4, v072
	.byte W12
	.byte TEMPO, 30
	.byte As5 @ N12, v072
	.byte W12
	.byte As4, v048 @ N12
	.byte W12
	.byte TEMPO, 40
	.byte Gn5, v040 @ N12
	.byte W12
	.byte Gn4, v048 @ N12
	.byte W12
	.byte Gn5, v080 @ N12
	.byte W12
	.byte Gn4, v052 @ N12
	.byte W12
	.byte TEMPO, 35
	.byte Gs5, v072 @ N12
	.byte W12
	.byte Gs4, v048 @ N12
	.byte W12
	.byte TEMPO, 40
	.byte En6 @ N12, v048
	.byte W12
	.byte En5, v076 @ N12
	.byte W12
	.byte En6, v084 @ N12
	.byte W12
	.byte En5, v076 @ N12
	.byte W12
	.byte Fn6, v084 @ N12
	.byte W12
	.byte Fn5, v068 @ N12
	.byte W12
	.byte En6 @ N12, v068
	.byte W12
	.byte En5, v048 @ N12
	.byte W12
	.byte TEMPO, 34
	.byte En6 @ N12, v048
	.byte W12
	.byte En5, v040 @ N12
	.byte W12
	.byte TEMPO, 27
	.byte Dn6 @ N12, v040
	.byte W12
	.byte Dn5 @ N12, v040
	.byte W12
	.byte W72
	.byte W72
	.byte GOTO
		.word track_8_lbl_25b6fe
	.byte FINE

track_8_1:
	.byte KEYSH, 0
track_8_lbl_25b7b4:
	.byte VOICE, 2
	.byte PAN, c_v
	.byte VOL, 62
	.byte PRIO, 109
	.byte N48, An4, v068
	.byte W72
	.byte As4 @ N48, v068
	.byte W72
	.byte Fs4 @ N48, v068
	.byte W72
	.byte Gn4 @ N48, v068
	.byte W68
	.byte W01
	.byte VOICE, 4
	.byte N60, Gn4, v080
	.byte W03
	.byte W72
	.byte VOICE, 2
	.byte N48, En4, v068
	.byte W72
	.byte Fn4 @ N48, v068
	.byte W72
	.byte Cn5, v080 @ N48
	.byte W72
	.byte As4, v068 @ N48
	.byte W68
	.byte W01
	.byte VOICE, 4
	.byte N60, As4, v080
	.byte W03
	.byte W72
	.byte W72
	.byte GOTO
		.word track_8_lbl_25b7b4
	.byte FINE

track_8_2:
	.byte KEYSH, 0
track_8_lbl_25b7ed:
	.byte VOICE, 3
	.byte PAN, c_v
	.byte VOL, 62
	.byte PRIO, 108
	.byte W36
	.byte N44, An4, v068
	.byte W36
	.byte W36
	.byte As4 @ N44, v068
	.byte W36
	.byte W36
	.byte Fs4 @ N44, v068
	.byte W36
	.byte W36
	.byte Gn4 @ N44, v068
	.byte W36
	.byte W72
	.byte W36
	.byte En4 @ N44, v068
	.byte W36
	.byte W36
	.byte Fn4 @ N44, v068
	.byte W36
	.byte W36
	.byte Cn5 @ N44, v068
	.byte W36
	.byte W36
	.byte As4 @ N44, v068
	.byte W36
	.byte W72
	.byte W72
	.byte GOTO
		.word track_8_lbl_25b7ed
	.byte FINE

track_8_3:
	.byte KEYSH, 0
track_8_lbl_25b81a:
	.byte VOICE, 6
	.byte PAN, c_v-20
	.byte VOL, 31
	.byte PRIO, 30
	.byte N12, An4, v048
	.byte W12
	.byte En5, v040 @ N12
	.byte W12
	.byte N24, An4, v048
	.byte W24
	.byte Gs4, v040 @ N24
	.byte W24
	.byte N12, Gn4, v052
	.byte W12
	.byte Dn5, v044 @ N12
	.byte W12
	.byte N24, Gn4 @ v044
	.byte W24
	.byte Fs4, v048 @ N24
	.byte W24
	.byte N12, An4 @ v048
	.byte W24
	.byte N24, An4, v064
	.byte W24
	.byte Gs4, v052 @ N24
	.byte W24
	.byte N12, Gn4, v048
	.byte W12
	.byte Dn5, v036 @ N12
	.byte W12
	.byte N24, Gn4, v048
	.byte W24
	.byte N36, Fs4 @ v048
	.byte W24
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte GOTO
		.word track_8_lbl_25b81a
	.byte FINE

track_8_4:
	.byte KEYSH, 0
track_8_lbl_25b864:
	.byte VOICE, 4
	.byte VOL, 62
	.byte PRIO, 30
	.byte W68
	.byte W01
	.byte N60, An4, v080
	.byte W03
	.byte W68
	.byte W01
	.byte As4 @ N60, v080
	.byte W03
	.byte W68
	.byte W01
	.byte Fs4 @ N60, v080
	.byte W03
	.byte W72
	.byte W72
	.byte W68
	.byte W01
	.byte En4 @ N60, v080
	.byte W03
	.byte W68
	.byte W01
	.byte Fn4 @ N60, v080
	.byte W03
	.byte W68
	.byte W01
	.byte Cn5 @ N60, v080
	.byte W03
	.byte W72
	.byte W72
	.byte W72
	.byte GOTO
		.word track_8_lbl_25b864
	.byte FINE

track_8_5:
	.byte KEYSH, 0
track_8_lbl_25b891:
	.byte VOICE, 1
	.byte PAN, c_v
	.byte VOL, 75
	.byte PRIO, 30
	.byte N03, En6, v044
	.byte W12
	.byte An5, v032 @ N03
	.byte W12
	.byte En6, v040 @ N03
	.byte W24
	.byte Ds6, v032 @ N03
	.byte W24
	.byte Dn6, v036 @ N03
	.byte W12
	.byte Gn5, v044 @ N03
	.byte W12
	.byte Dn6, v048 @ N03
	.byte W24
	.byte Cs6 @ N03, v048
	.byte W24
	.byte En6 @ N03, v048
	.byte W12
	.byte Fs5, v036 @ N03
	.byte W12
	.byte En6, v040 @ N03
	.byte W24
	.byte Ds6 @ N03, v040
	.byte W24
	.byte Dn6, v024 @ N03
	.byte W12
	.byte Gn5, v032 @ N03
	.byte W12
	.byte Dn6, v040 @ N03
	.byte W24
	.byte Cs6 @ N03, v040
	.byte W24
	.byte W72
	.byte An5, v052 @ N03
	.byte W24
	.byte N03 @ An5, v052
	.byte W24
	.byte As5 @ N03, v052
	.byte W24
	.byte Gn5 @ N03, v052
	.byte W24
	.byte N03 @ Gn5, v052
	.byte W24
	.byte Gs5 @ N03, v052
	.byte W24
	.byte W24
	.byte En6, v064 @ N03
	.byte W48
	.byte W24
	.byte En6, v036 @ N03
	.byte W24
	.byte Dn6, v028 @ N03
	.byte W24
	.byte W72
	.byte W72
	.byte GOTO
		.word track_8_lbl_25b891
	.byte FINE

.align 2

track_8:
	.byte 6
	.byte 8
	.byte 130
	.byte 128
	.word 0x80a5ca4
	.word track_8_0
	.word track_8_1
	.word track_8_2
	.word track_8_3
	.word track_8_4
	.word track_8_5

.align 2
